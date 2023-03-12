
void TS_compute_imprint(BIO *param_1,undefined4 param_2,X509_ALGOR **param_3,uchar **param_4,
                       int *param_5)

{
  X509_ALGOR *pXVar1;
  int iVar2;
  char *name;
  EVP_MD *md;
  uchar *puVar3;
  undefined4 uVar4;
  size_t cnt;
  EVP_MD_CTX EStack_103c;
  undefined auStack_1024 [4096];
  int local_24;
  
  local_24 = __stack_chk_guard;
  TS_TST_INFO_get_msg_imprint(param_2);
  pXVar1 = (X509_ALGOR *)TS_MSG_IMPRINT_get_algo();
  *param_3 = (X509_ALGOR *)0x0;
  *param_4 = (uchar *)0x0;
  pXVar1 = X509_ALGOR_dup(pXVar1);
  *param_3 = pXVar1;
  if (pXVar1 != (X509_ALGOR *)0x0) {
    iVar2 = OBJ_obj2nid(pXVar1->algorithm);
    name = OBJ_nid2sn(iVar2);
    md = EVP_get_digestbyname(name);
    if (md == (EVP_MD *)0x0) {
      ERR_put_error(0x2f,0x91,0x7e,"ts_rsp_verify.c",0x265);
      pXVar1 = *param_3;
    }
    else {
      iVar2 = EVP_MD_size(md);
      if (-1 < iVar2) {
        *param_5 = iVar2;
        puVar3 = (uchar *)CRYPTO_malloc(iVar2,"ts_rsp_verify.c",0x26e);
        *param_4 = puVar3;
        if (puVar3 == (uchar *)0x0) {
          ERR_put_error(0x2f,0x91,0x41,"ts_rsp_verify.c",0x26f);
          pXVar1 = *param_3;
          goto LAB_000e9d86;
        }
        iVar2 = EVP_DigestInit(&EStack_103c,md);
        while (iVar2 != 0) {
          cnt = BIO_read(param_1,auStack_1024,0x1000);
          if ((int)cnt < 1) {
            iVar2 = EVP_DigestFinal(&EStack_103c,*param_4,(uint *)0x0);
            if (iVar2 != 0) {
              uVar4 = 1;
              goto LAB_000e9d98;
            }
            break;
          }
          iVar2 = EVP_DigestUpdate(&EStack_103c,auStack_1024,cnt);
        }
      }
      pXVar1 = *param_3;
    }
  }
LAB_000e9d86:
  X509_ALGOR_free(pXVar1);
  CRYPTO_free(*param_4);
  uVar4 = 0;
  *param_5 = 0;
  *param_4 = (uchar *)0x0;
LAB_000e9d98:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}

