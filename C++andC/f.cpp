void __fastcall TFormPaperCheck::DecodePaper(void)
{
        TIniFile *pPaperFile;
        TIniFile *pUserFile;
        AnsiString PaperFilePath, UserFilePath, IniSection, sScore;
        void* pItem;
        int i, QsType, l1, l2, beginitem, QsNum,tmpindex;
        AnsiString xscore[5];
        int b1,b2,b3,b4,b5;

        PaperFilePath = TefDir + "\\Paper.ini";
        UserFilePath = TafDir + "\\" + UserId + ".ini";

        if(!FileExists(PaperFilePath))
        {
                Application->MessageBox("找不到对应的试卷文件！", "警告", MB_OK);
                return;
        }

        if(!FileExists(UserFilePath))
        {
                Application->MessageBox("找不到考生的答卷文件！", "警告", MB_OK);
                return;
        }

        if(pMyPaper)
                FreePaper();

        pMyPaper = (LsTestPaperStru*)malloc(sizeof(LsTestPaperStru)+1);
        memset(pMyPaper, 0, sizeof(LsTestPaperStru)+1);

        pPaperFile = new TIniFile(PaperFilePath);
        
        pMyPaper->itemNum = pPaperFile->ReadInteger("Paper", "PaperItem", 22);
        //pMyPaper->itemNum = 22;
        pMyPaper->paperId = pPaperFile->ReadInteger("Paper", "PaperId", 4001);
        pMyPaper->paperType = pPaperFile->ReadInteger("Paper", "PaperType", 2);
        pMyPaper->iFullConfen = 40;
        pMyPaper->iConf = 0;

        pUserFile = new TIniFile(UserFilePath);

        beginitem=0;
        l1=5;
        l2=0;
        for(i=0;i<pMyPaper->itemNum;i++)
        {
                /*
                if(i <= 11)
                {
                        IniSection.sprintf("ITEM%2.2d", i+1);
                }
                else if(i >= 12 && i <= 16 )
                {
                        tmpindex = 13;
                        IniSection.sprintf("ITEM%2.2d", tmpindex);
                }
                else if(i >= 17 && i <= 21 )
                {
                        tmpindex = 14;
                        IniSection.sprintf("ITEM%2.2d", tmpindex);
                }
                */
                IniSection.sprintf("ITEM%2.2d", i+1);
                QsType = pPaperFile->ReadInteger(IniSection, "QsType", 2);
                switch(QsType)
                {


                case 1002:         //听力选答案
                        pItem = new ListenItem2;
                        memset(pItem, 0, sizeof(ListenItem2));
                        FormatListenType2(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[beginitem++] = pItem;
                        break;

                case 1012:         //听力选答案
                        pItem = new ListenItem2;
                        memset(pItem, 0, sizeof(ListenItem2));
                        FormatListenType2(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[l1++] = pItem;
                        break;

                case 1022:         //听力选答案
                        pItem = new ListenItem2;
                        memset(pItem, 0, sizeof(ListenItem2));
                        FormatListenType2(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[10] = pItem;
                        break;

                case 1003:         //阅读题
                        pItem = new SpeakItem1;
                        memset(pItem, 0, sizeof(SpeakItem1));
                        FormatSpeakType1(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[11] = pItem;
                        break;

                case 1006:         //描述题
                        pItem = new SpeakItem5;
                        memset(pItem, 0, sizeof(SpeakItem5));
                        FormatSpeakType51(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[12] = pItem;
                        break;

                case 1016:
                        pItem = new SpeakItem6;
                        memset(pItem, 0, sizeof(SpeakItem6));
                        FormatSpeakType5(pItem, IniSection, pPaperFile, pUserFile);
                        pMyPaper->itemArray[13] = pItem;
                        break;
                }
        }

        //增加到试题列表
        TListItem* pTempItem;
        int iItemType, j, score;
        //for(i=0;i<pMyPaper->itemNum;i++)
        for(i=0;i<22;i++)
        {
                if(i<=11)
                {
                        iItemType = *(int*)pMyPaper->itemArray[i];
                }
                else if(i>=12 && i<=16)
                {
                        iItemType = *(int*)pMyPaper->itemArray[12];
                }
                else if(i>=17 && i<=21)
                {
                        iItemType = *(int*)pMyPaper->itemArray[13];
                }
                switch(iItemType)
                {


                case TESTTYPE_LISTEN_1:
                case TESTTYPE_LISTEN_2:
                case TESTTYPE_LISTEN_3:
                        mpListenItem2 = (ListenItem2 *)pMyPaper->itemArray[i];
                        pTempItem = ItemListView->Items->Add();
                        pTempItem->Caption = mpListenItem2->itemIndex;
                        score = 0;
                        for(int j=0;j<mpListenItem2->numSubItems;j++)
                        {
                                if(mpListenItem2->subItem[j].testResult==mpListenItem2->subItem[j].rightResult)
                                        score++;
                        }
                        pTempItem->SubItems->Add(score);
                        pMyPaper->iConf += score*10;
                        break;

                case TESTTYPE_SPEAK_ITEM_0:
                        mpSpeakItem1 = (SpeakItem1 *)pMyPaper->itemArray[i];
                        pTempItem = ItemListView->Items->Add();
                        pTempItem->Caption = mpSpeakItem1->itemIndex;
                        sScore.sprintf("%d.%d", mpSpeakItem1->ItemConf/10, mpSpeakItem1->ItemConf%10);
                        pTempItem->SubItems->Add(sScore);
                        pMyPaper->iConf += mpSpeakItem1->ItemConf;
                        break;

                case TESTTYPE_SPEAK_ITEM_4:
                        mpSpeakItem5 = (SpeakItem5 *)pMyPaper->itemArray[12];
                        pTempItem = ItemListView->Items->Add();
                        pTempItem->Caption = mpSpeakItem5->itemIndex;
                        //sScore.sprintf("%d.%d", mpSpeakItem5->ItemConf/10, mpSpeakItem5->ItemConf%10);
                        //pTempItem->SubItems->Add(sScore);
                        //pMyPaper->iConf += mpSpeakItem5->ItemConf;
                        for(int h = 0; h<5 ;h++)
                        {
                                        xscore[h] = "";
                        }
                        TsCutStringByXieGang(mpSpeakItem5->qjtwconf,xscore,5);
                        if(i == 12)
                        {
                                b1 = StrToInt(xscore[0]);
                                sScore.sprintf("%d.%d", b1/10, b1%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 13)
                        {
                                b2 = StrToInt(xscore[1]);
                                sScore.sprintf("%d.%d", b2/10, b2%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 14)
                        {
                                b3 = StrToInt(xscore[2]);
                                sScore.sprintf("%d.%d", b3/10, b3%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 15)
                        {
                                b4 = StrToInt(xscore[3]);
                                sScore.sprintf("%d.%d", b4/10, b4%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 16)
                        {
                                b5 = StrToInt(xscore[4]);
                                sScore.sprintf("%d.%d", b5/10, b5%10);
                                pTempItem->SubItems->Add(sScore);

                                b1 = b1 + b2 + b3 + b4 + b5;
                                pMyPaper->iConf += b1;
                        }
                        //sScore.sprintf("%d.%d", mpSpeakItem5->ItemConf/10, mpSpeakItem5->ItemConf%10);
                        //pTempItem->SubItems->Add(sScore);

                        break;

                case TESTTYPE_SPEAK_ITEM_5:
                        mpSpeakItem6 = (SpeakItem6 *)pMyPaper->itemArray[13];
                        pTempItem = ItemListView->Items->Add();
                        pTempItem->Caption = mpSpeakItem6->itemIndex;
                        //sScore.sprintf("%d.%d", mpSpeakItem6->ItemConf/10, mpSpeakItem6->ItemConf%10);
                        //pTempItem->SubItems->Add(sScore);
                        //pMyPaper->iConf += mpSpeakItem6->ItemConf;

                        for(int h = 0; h<5 ;h++)
                        {
                                        xscore[h] = "";
                        }
                        TsCutStringByXieGang(mpSpeakItem6->qjydconf,xscore,5);
                        if(i == 17)
                        {
                                b1 = StrToInt(xscore[0]);
                                sScore.sprintf("%d.%d", b1/10, b1%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 18)
                        {
                                b2 = StrToInt(xscore[1]);
                                sScore.sprintf("%d.%d", b2/10, b2%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 19)
                        {
                                b3 = StrToInt(xscore[2]);
                                sScore.sprintf("%d.%d", b3/10, b3%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 20)
                        {
                                b4 = StrToInt(xscore[3]);
                                sScore.sprintf("%d.%d", b4/10, b4%10);
                                pTempItem->SubItems->Add(sScore);
                        }
                        if(i == 21)
                        {
                                b5 = StrToInt(xscore[4]);
                                sScore.sprintf("%d.%d", b5/10, b5%10);
                                pTempItem->SubItems->Add(sScore);
                                
                                b1 = b1 + b2 + b3 + b4 + b5;
                                pMyPaper->iConf += b1;
                        }


                        break;

                default:
                        break;
                }
        }
        
        delete pPaperFile;
        delete pUserFile;

}






















void __fastcall TFormPaperCheck::FormatListenType1(void* pItem, AnsiString IniSection, TIniFile *pIniFile, TIniFile *pUserIniFile)
{
        int StartTime, EndTime, PlayTime, QsNum, AnswerNum;
        int TestId;
        AnsiString SpeechText,QsText,SpeechPath, RightId;
        AnsiString BmpAnswer1, BmpAnswer2, BmpAnswer3, BmpAnswer4;
        ListenItem1* pTestItem = (ListenItem1*)pItem;

        TestId = pIniFile->ReadInteger(IniSection, "TestId", 0);
        SpeechText = pIniFile->ReadString(IniSection, "SpeechText", "");
        TsRNStr(&SpeechText);

        QsText = pIniFile->ReadString(IniSection, "QsText", "");
        SpeechPath = pIniFile->ReadString(IniSection, "SpeechPath", "");

        StartTime = pIniFile->ReadInteger(IniSection, "StartTime", 0);
        EndTime = pIniFile->ReadInteger(IniSection, "EndTime", 0);
        PlayTime = pIniFile->ReadInteger(IniSection, "PlayTime", 1);
        //QsNum = pIniFile->ReadInteger(IniSection, "QsNum", 1);
        AnswerNum = pIniFile->ReadInteger(IniSection, "AnswerNum", 3);

        RightId = pIniFile->ReadString(IniSection, "RightId", "");
        BmpAnswer1 = pIniFile->ReadString(IniSection, "BmpAnswer1", "");
        BmpAnswer2 = pIniFile->ReadString(IniSection, "BmpAnswer2", "");
        BmpAnswer3 = pIniFile->ReadString(IniSection, "BmpAnswer3", "");
        if(AnswerNum == 4)
                BmpAnswer4 = pIniFile->ReadString(IniSection, "BmpAnswer4", "");

        pTestItem->itemId = TESTTYPE_LISTEN_0;
        pTestItem->itemIndex = TestId;
        pTestItem->pTitle = "本部分共有10道小题，每小题你将听到一段对话，每段对话听两遍。在听每段对话前，你将有5秒钟的时间阅读题目；听完后，你还有5秒钟的时间在屏幕上点击你认为最合适的备选答案。在听到“嘀”的信号后，进入下一小题。";

        TsFormatAnsiStringToChar(SpeechText, &(pTestItem->itemStr[0]));
        if(QsText.Length()>0)
                TsFormatAnsiStringToChar(QsText, &(pTestItem->questionStr));
        TsFormatAnsiStringToChar(SpeechPath, &pTestItem->voicePath);

        pTestItem->voiceStartPos = StartTime;
        pTestItem->voiceEndPos = EndTime;
        pTestItem->playNum = PlayTime;
        pTestItem->rightResult = StrToInt(RightId) + 1;
        
        //备选答案图片
        pTestItem->bmpPath1=TefDir + "\\" + BmpAnswer1;

        pTestItem->bmpPath2 =TefDir + "\\" + BmpAnswer2;

        pTestItem->bmpPath3 =TefDir + "\\" + BmpAnswer3;
        //第四个选择
        if(AnswerNum == 4)
        {
                pTestItem->bmpPath4 =TefDir + "\\" + BmpAnswer4;
        }

        //搜索该题用户答案
        int ItemNum = pUserIniFile->ReadInteger("Paper", "PaperItem", 0);
        int Id;
        AnsiString IniSect;
        for(int i=0;i<ItemNum;i++)
        {
                IniSect.sprintf("ITEM%2.2d", i+1);
                Id = pUserIniFile->ReadInteger(IniSect, "TestId", 0);
                if(TestId == Id)
                        break;
        }

        pTestItem->testResult = pUserIniFile->ReadInteger(IniSect, "UserResult", 0);

}







