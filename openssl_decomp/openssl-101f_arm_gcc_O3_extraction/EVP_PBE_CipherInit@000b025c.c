
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  char *pcVar4;
  EVP_MD *pEVar5;
  int n;
  EVP_MD *pEVar6;
  code *pcVar7;
  undefined4 local_90;
  int local_8c;
  char acStack_7c [80];
  int local_2c;
  
  local_2c = __TMC_END__;
  iVar1 = OBJ_obj2nid(pbe_obj);
  if (iVar1 != 0) {
    local_90 = 0;
    local_8c = iVar1;
    if ((((pbe_algs != (_STACK *)0x0) && (iVar1 = sk_find(pbe_algs,&local_90), iVar1 != -1)) &&
        (pvVar2 = sk_value(pbe_algs,iVar1), pvVar2 != (void *)0x0)) ||
       (pvVar2 = OBJ_bsearch_(&local_90,&builtin_pbe,0x15,0x14,pbe2_cmp_BSEARCH_CMP_FN + 1),
       pvVar2 != (void *)0x0)) {
      n = *(int *)((int)pvVar2 + 8);
      iVar1 = *(int *)((int)pvVar2 + 0xc);
      pcVar7 = *(code **)((int)pvVar2 + 0x10);
      pcVar4 = pass;
      if ((pass != (char *)0x0) && (pcVar4 = (char *)passlen, passlen == -1)) {
        pcVar4 = (char *)strlen(pass);
      }
      if (n == -1) {
        pEVar6 = (EVP_MD *)0x0;
        if (iVar1 != -1) goto LAB_000b033c;
LAB_000b036c:
        pEVar5 = (EVP_MD *)0x0;
      }
      else {
        pcVar3 = OBJ_nid2sn(n);
        pEVar5 = (EVP_MD *)EVP_get_cipherbyname(pcVar3);
        if (pEVar5 == (EVP_MD *)0x0) {
          ERR_put_error(6,0x74,0xa0,"evp_pbe.c",0xba);
          goto LAB_000b02f8;
        }
        pEVar6 = pEVar5;
        if (iVar1 == -1) goto LAB_000b036c;
LAB_000b033c:
        pcVar3 = OBJ_nid2sn(iVar1);
        pEVar5 = EVP_get_digestbyname(pcVar3);
        if (pEVar5 == (EVP_MD *)0x0) {
          ERR_put_error(6,0x74,0xa1,"evp_pbe.c",0xc6);
          goto LAB_000b02f8;
        }
      }
      pEVar5 = (EVP_MD *)(*pcVar7)(ctx,pass,pcVar4,param,pEVar6,pEVar5,en_de);
      if (pEVar5 == (EVP_MD *)0x0) {
        ERR_put_error(6,0x74,0x78,"evp_pbe.c",0xcd);
      }
      else {
        pEVar5 = (EVP_MD *)0x1;
      }
      goto LAB_000b02f8;
    }
  }
  ERR_put_error(6,0x74,0x79,"evp_pbe.c",0xa7);
  if (pbe_obj == (ASN1_OBJECT *)0x0) {
    BUF_strlcpy(acStack_7c,"NULL",0x50);
  }
  else {
    i2t_ASN1_OBJECT(acStack_7c,0x50,pbe_obj);
  }
  ERR_add_error_data(2,"TYPE=",acStack_7c);
  pEVar5 = (EVP_MD *)0x0;
LAB_000b02f8:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pEVar5;
}

