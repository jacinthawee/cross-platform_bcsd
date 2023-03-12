
int cms_DigestAlgorithm_find_ctx(EVP_MD_CTX *param_1,BIO *param_2,X509_ALGOR *param_3)

{
  int iVar1;
  EVP_MD *pEVar2;
  int iVar3;
  BIO *bp;
  int in_GS_OFFSET;
  ASN1_OBJECT *local_28;
  EVP_MD_CTX *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  X509_ALGOR_get0(&local_28,(int *)0x0,(void **)0x0,param_3);
  iVar1 = OBJ_obj2nid(local_28);
  do {
    bp = BIO_find_type(param_2,0x208);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x73,0x83,"cms_lib.c",0x195);
      iVar1 = 0;
LAB_0818c5f0:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return iVar1;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    BIO_ctrl(bp,0x78,0,&local_24);
    pEVar2 = EVP_MD_CTX_md(local_24);
    iVar3 = EVP_MD_type(pEVar2);
    if (iVar1 == iVar3) {
LAB_0818c5e0:
      iVar1 = EVP_MD_CTX_copy_ex(param_1,local_24);
      goto LAB_0818c5f0;
    }
    pEVar2 = EVP_MD_CTX_md(local_24);
    iVar3 = EVP_MD_pkey_type(pEVar2);
    if (iVar1 == iVar3) goto LAB_0818c5e0;
    param_2 = BIO_next(bp);
  } while( true );
}

