
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  code *pcVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  EVP_CIPHER *pEVar5;
  EVP_MD *pEVar6;
  int in_GS_OFFSET;
  int iVar7;
  undefined4 local_84;
  int local_80;
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = OBJ_obj2nid(pbe_obj);
  if ((iVar2 == 0) ||
     ((((local_84 = 0, local_80 = iVar2, pbe_algs == (_STACK *)0x0 ||
        (iVar2 = sk_find(pbe_algs,&local_84), iVar2 == -1)) ||
       (pvVar3 = sk_value(pbe_algs,iVar2), pvVar3 == (void *)0x0)) &&
      (pvVar3 = OBJ_bsearch_(&local_84,builtin_pbe,0x15,0x14,pbe2_cmp_BSEARCH_CMP_FN),
      pvVar3 == (void *)0x0)))) {
    ERR_put_error(6,0x74,0x79,"evp_pbe.c",0xa2);
    if (pbe_obj == (ASN1_OBJECT *)0x0) {
      BUF_strlcpy(local_70,"NULL",0x50);
    }
    else {
      i2t_ASN1_OBJECT(local_70,0x50,pbe_obj);
    }
    ERR_add_error_data(2,"TYPE=",local_70);
    iVar2 = 0;
    goto LAB_08131e2d;
  }
  iVar2 = *(int *)((int)pvVar3 + 8);
  iVar7 = *(int *)((int)pvVar3 + 0xc);
  pcVar1 = *(code **)((int)pvVar3 + 0x10);
  if (pass == (char *)0x0) {
    passlen = 0;
  }
  else if (passlen == -1) {
    passlen = strlen(pass);
  }
  if (iVar2 == -1) {
    pEVar5 = (EVP_CIPHER *)0x0;
    if (iVar7 != -1) goto LAB_08131f04;
LAB_08131f8b:
    pEVar6 = (EVP_MD *)0x0;
LAB_08131f28:
    iVar2 = (*pcVar1)(ctx,pass,passlen,param,pEVar5,pEVar6,en_de);
    if (iVar2 == 0) {
      ERR_put_error(6,0x74,0x78,"evp_pbe.c",0xc5);
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    pcVar4 = OBJ_nid2sn(iVar2);
    pEVar5 = EVP_get_cipherbyname(pcVar4);
    if (pEVar5 == (EVP_CIPHER *)0x0) {
      iVar7 = 0xb5;
      iVar2 = 0xa0;
    }
    else {
      if (iVar7 == -1) goto LAB_08131f8b;
LAB_08131f04:
      pcVar4 = OBJ_nid2sn(iVar7);
      pEVar6 = EVP_get_digestbyname(pcVar4);
      if (pEVar6 != (EVP_MD *)0x0) goto LAB_08131f28;
      iVar7 = 0xbf;
      iVar2 = 0xa1;
    }
    ERR_put_error(6,0x74,iVar2,"evp_pbe.c",iVar7);
    iVar2 = 0;
  }
LAB_08131e2d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

