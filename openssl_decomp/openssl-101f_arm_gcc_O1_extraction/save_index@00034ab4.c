
BIO * save_index(char *param_1,char *param_2,int *param_3)

{
  BIO_METHOD *pBVar1;
  BIO *pBVar2;
  size_t sVar3;
  size_t sVar4;
  long lVar5;
  undefined1 *puVar6;
  char acStack_318 [256];
  char acStack_218 [256];
  char acStack_118 [256];
  
  pBVar1 = BIO_s_file();
  pBVar2 = BIO_new(pBVar1);
  if (pBVar2 == (BIO *)0x0) {
    ERR_print_errors(bio_err);
  }
  else {
    sVar3 = strlen(param_1);
    sVar4 = strlen(param_2);
    if (0xf9 < (int)(sVar4 + sVar3)) {
      BIO_printf(bio_err,"file name too long\n");
      return (BIO *)0x0;
    }
    BIO_snprintf(acStack_118,0x100,"%s.attr",param_1);
    BIO_snprintf(acStack_218,0x100,"%s.attr.%s",param_1,param_2);
    BIO_snprintf(acStack_318,0x100,"%s.%s",param_1,param_2);
    lVar5 = BIO_ctrl(pBVar2,0x6c,5,acStack_318);
    if (lVar5 < 1) {
      perror(param_1);
      BIO_printf(bio_err,"unable to open \'%s\'\n",param_1);
      return (BIO *)0x0;
    }
    lVar5 = TXT_DB_write(pBVar2,(TXT_DB *)param_3[1]);
    if (lVar5 < 1) {
      pBVar2 = (BIO *)0x0;
    }
    else {
      BIO_free(pBVar2);
      pBVar1 = BIO_s_file();
      pBVar2 = BIO_new(pBVar1);
      lVar5 = BIO_ctrl(pBVar2,0x6c,5,acStack_218);
      if (lVar5 < 1) {
        perror(acStack_118);
        BIO_printf(bio_err,"unable to open \'%s\'\n",acStack_118);
        pBVar2 = (BIO *)0x0;
      }
      else {
        puVar6 = &UNK_001330a4;
        if (*param_3 != 0) {
          puVar6 = &DAT_001330a0;
        }
        BIO_printf(pBVar2,"unique_subject = %s\n",puVar6);
        BIO_free(pBVar2);
        pBVar2 = (BIO *)0x1;
      }
    }
  }
  return pBVar2;
}

