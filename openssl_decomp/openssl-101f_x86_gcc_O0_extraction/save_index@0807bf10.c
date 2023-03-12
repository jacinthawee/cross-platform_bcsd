
undefined4 save_index(char *param_1,char *param_2,int *param_3)

{
  BIO_METHOD *pBVar1;
  BIO *pBVar2;
  size_t sVar3;
  size_t sVar4;
  long lVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int in_GS_OFFSET;
  char local_320 [256];
  char local_220 [256];
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pBVar1 = BIO_s_file();
  pBVar2 = BIO_new(pBVar1);
  if (pBVar2 == (BIO *)0x0) {
    uVar7 = 0;
    ERR_print_errors(bio_err);
  }
  else {
    sVar3 = strlen(param_1);
    sVar4 = strlen(param_2);
    if ((int)(sVar3 + sVar4) < 0xfa) {
      BIO_snprintf(local_120,0x100,"%s.attr",param_1);
      BIO_snprintf(local_220,0x100,"%s.attr.%s",param_1,param_2);
      BIO_snprintf(local_320,0x100,"%s.%s",param_1,param_2);
      lVar5 = BIO_ctrl(pBVar2,0x6c,5,local_320);
      if (lVar5 < 1) {
        perror(param_1);
        uVar7 = 0;
        BIO_printf(bio_err,"unable to open \'%s\'\n",param_1);
      }
      else {
        uVar7 = 0;
        lVar5 = TXT_DB_write(pBVar2,(TXT_DB *)param_3[1]);
        if (0 < lVar5) {
          BIO_free(pBVar2);
          pBVar1 = BIO_s_file();
          pBVar2 = BIO_new(pBVar1);
          lVar5 = BIO_ctrl(pBVar2,0x6c,5,local_220);
          if (lVar5 < 1) {
            perror(local_120);
            BIO_printf(bio_err,"unable to open \'%s\'\n",local_120);
          }
          else {
            uVar7 = 1;
            puVar6 = &UNK_081f75bd;
            if (*param_3 == 0) {
              puVar6 = &UNK_081f75c1;
            }
            BIO_printf(pBVar2,"unique_subject = %s\n",puVar6);
            BIO_free(pBVar2);
          }
        }
      }
    }
    else {
      uVar7 = 0;
      BIO_printf(bio_err,"file name too long\n");
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

