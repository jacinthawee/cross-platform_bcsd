
undefined4 __regparm3
TS_compute_imprint(BIO *param_1_00,undefined4 param_2_00,X509_ALGOR **param_3,uchar **param_1,
                  int *param_2)

{
  undefined4 uVar1;
  X509_ALGOR *pXVar2;
  int iVar3;
  char *name;
  EVP_MD *md;
  uchar *puVar4;
  size_t cnt;
  int in_GS_OFFSET;
  int line;
  EVP_MD_CTX local_1038;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = TS_TST_INFO_get_msg_imprint(param_2_00);
  pXVar2 = (X509_ALGOR *)TS_MSG_IMPRINT_get_algo(uVar1);
  *param_3 = (X509_ALGOR *)0x0;
  *param_1 = (uchar *)0x0;
  pXVar2 = X509_ALGOR_dup(pXVar2);
  *param_3 = pXVar2;
  if (pXVar2 == (X509_ALGOR *)0x0) goto LAB_081971b2;
  iVar3 = OBJ_obj2nid(pXVar2->algorithm);
  name = OBJ_nid2sn(iVar3);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    line = 0x25a;
    iVar3 = 0x7e;
LAB_0819725f:
    ERR_put_error(0x2f,0x91,iVar3,"ts_rsp_verify.c",line);
    pXVar2 = *param_3;
  }
  else {
    iVar3 = EVP_MD_size(md);
    if (-1 < iVar3) {
      *param_2 = iVar3;
      puVar4 = (uchar *)CRYPTO_malloc(iVar3,"ts_rsp_verify.c",0x263);
      *param_1 = puVar4;
      if (puVar4 == (uchar *)0x0) {
        line = 0x265;
        iVar3 = 0x41;
        goto LAB_0819725f;
      }
      iVar3 = EVP_DigestInit(&local_1038,md);
      while (iVar3 != 0) {
        cnt = BIO_read(param_1_00,local_1020,0x1000);
        if ((int)cnt < 1) {
          iVar3 = EVP_DigestFinal(&local_1038,*param_1,(uint *)0x0);
          uVar1 = 1;
          if (iVar3 != 0) goto LAB_081971d2;
          break;
        }
        iVar3 = EVP_DigestUpdate(&local_1038,local_1020,cnt);
      }
    }
    pXVar2 = *param_3;
  }
LAB_081971b2:
  X509_ALGOR_free(pXVar2);
  CRYPTO_free(*param_1);
  *param_2 = 0;
  uVar1 = 0;
LAB_081971d2:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

