
undefined4
do_fp(BIO *param_1,uchar *param_2,BIO *param_3,int param_4,int param_5,int param_6,uchar *param_7,
     size_t *param_8,int param_9,size_t *param_10,size_t *param_11)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  char *format;
  size_t local_28;
  EVP_MD_CTX *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    iVar2 = BIO_read(param_3,param_2,0x2000);
    if (iVar2 < 0) {
      format = "Read Error in %s\n";
      param_8 = param_11;
      goto LAB_0805107c;
    }
  } while (iVar2 != 0);
  if (param_7 == (uchar *)0x0) {
    if (param_6 == 0) {
      param_8 = (size_t *)0x2000;
      local_28 = BIO_gets(param_3,(char *)param_2,0x2000);
      if ((int)local_28 < 0) {
        ERR_print_errors(bio_err);
        uVar3 = 1;
        goto LAB_0805109b;
      }
    }
    else {
      BIO_ctrl(param_3,0x78,0,&local_24);
      local_28 = 0x2000;
      param_8 = &local_28;
      iVar2 = EVP_DigestSignFinal(local_24,param_2,param_8);
      if (iVar2 == 0) {
        format = "Error Signing Data\n";
        goto LAB_0805107c;
      }
    }
    if (param_5 == 0) {
      if (param_4 == 2) {
        if (0 < (int)local_28) {
          iVar2 = 0;
          do {
            pbVar1 = param_2 + iVar2;
            iVar2 = iVar2 + 1;
            BIO_printf(param_1,"%02x",(uint)*pbVar1);
          } while (iVar2 < (int)local_28);
        }
        BIO_printf(param_1," *%s\n",param_11);
        uVar3 = 0;
      }
      else {
        if (param_9 == 0) {
          if (param_10 == (size_t *)0x0) {
            BIO_printf(param_1,"(%s)= ",param_11);
            param_10 = param_11;
          }
          else {
            BIO_printf(param_1,"%s(%s)= ",param_10,param_11);
          }
        }
        else {
          BIO_printf(param_1,"%s-%s(%s)= ",param_9,param_10,param_11);
          param_10 = param_8;
        }
        if (0 < (int)local_28) {
          iVar2 = 0;
          while( true ) {
            param_10 = (size_t *)(uint)param_2[iVar2];
            iVar2 = iVar2 + 1;
            BIO_printf(param_1,"%02x",param_10);
            if ((int)local_28 <= iVar2) break;
            if ((param_4 != 0) && (iVar2 != 0)) {
              BIO_printf(param_1,":",param_10);
            }
          }
        }
        BIO_printf(param_1,"\n",param_10);
        uVar3 = 0;
      }
    }
    else {
      BIO_write(param_1,param_2,local_28);
      uVar3 = 0;
    }
  }
  else {
    BIO_ctrl(param_3,0x78,0,&local_24);
    iVar2 = EVP_DigestVerifyFinal(local_24,param_7,(size_t)param_8);
    if (0 < iVar2) {
      BIO_printf(param_1,"Verified OK\n");
      uVar3 = 0;
      goto LAB_0805109b;
    }
    if (iVar2 == 0) {
      BIO_printf(param_1,"Verification Failure\n");
      uVar3 = 1;
      goto LAB_0805109b;
    }
    format = "Error Verifying Data\n";
LAB_0805107c:
    BIO_printf(bio_err,format,param_8);
    ERR_print_errors(bio_err);
    uVar3 = 1;
  }
LAB_0805109b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

