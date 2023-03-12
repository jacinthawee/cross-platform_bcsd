
int EVP_PBE_CipherInit(ASN1_OBJECT *pbe_obj,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER_CTX *ctx,int en_de)

{
  undefined *puVar1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  EVP_MD *pEVar4;
  int *data;
  char *pcVar5;
  int iVar6;
  code *pcVar7;
  EVP_CIPHER *line;
  undefined4 local_90;
  int local_8c;
  char acStack_7c [80];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)();
  if (iVar2 == 0) {
LAB_005431a4:
    pcVar5 = "evp_pbe.c";
    line = (EVP_CIPHER *)&DAT_000000a2;
    ERR_put_error(6,0x74,0x79,"evp_pbe.c",0xa2);
    if (pbe_obj == (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_BUF_strlcpy_006a6f64)(acStack_7c,"NULL",0x50);
      param = (ASN1_TYPE *)pcVar5;
    }
    else {
      i2t_ASN1_OBJECT(acStack_7c,0x50,pbe_obj);
      param = (ASN1_TYPE *)pcVar5;
    }
    passlen = (int)acStack_7c;
    pass = "TYPE=";
    ERR_add_error_data(2);
    iVar2 = 0;
    goto LAB_0054320c;
  }
  local_90 = 0;
  local_8c = iVar2;
  if (((pbe_algs == (_STACK *)0x0) || (iVar2 = sk_find(pbe_algs,&local_90), iVar2 == -1)) ||
     (pvVar3 = sk_value(pbe_algs,iVar2), pvVar3 == (void *)0x0)) {
    pvVar3 = (void *)(*(code *)PTR_OBJ_bsearch__006a8368)
                               (&local_90,builtin_pbe,0x15,0x14,pbe2_cmp_BSEARCH_CMP_FN);
    if (pvVar3 == (void *)0x0) goto LAB_005431a4;
    iVar2 = *(int *)((int)pvVar3 + 8);
  }
  else {
    iVar2 = *(int *)((int)pvVar3 + 8);
  }
  iVar6 = *(int *)((int)pvVar3 + 0xc);
  pcVar7 = *(code **)((int)pvVar3 + 0x10);
  if (pass == (char *)0x0) {
    passlen = 0;
  }
  else if (passlen == -1) {
    passlen = (*(code *)PTR_strlen_006a9a24)(pass);
  }
  if (iVar2 == -1) {
    line = (EVP_CIPHER *)0x0;
joined_r0x0054337c:
    if (iVar6 != -1) {
      pcVar5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(iVar6);
      pEVar4 = EVP_get_digestbyname(pcVar5);
      if (pEVar4 == (EVP_MD *)0x0) {
        passlen = 0xa1;
        line = (EVP_CIPHER *)0xbf;
        goto LAB_00543414;
      }
    }
    iVar2 = (*pcVar7)(ctx);
    if (iVar2 == 0) {
      passlen = (int)&DAT_00000078;
      pcVar5 = "evp_pbe.c";
      line = (EVP_CIPHER *)0xc5;
      pass = &DAT_00000074;
      ERR_put_error(6,0x74,0x78,"evp_pbe.c",0xc5);
      param = (ASN1_TYPE *)pcVar5;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    pcVar5 = (char *)(*(code *)PTR_OBJ_nid2sn_006a709c)(iVar2);
    line = EVP_get_cipherbyname(pcVar5);
    if (line != (EVP_CIPHER *)0x0) goto joined_r0x0054337c;
    passlen = (int)&DAT_000000a0;
    line = (EVP_CIPHER *)0xb5;
LAB_00543414:
    pcVar5 = "evp_pbe.c";
    pass = &DAT_00000074;
    ERR_put_error(6,0x74,passlen,"evp_pbe.c",(int)line);
    iVar2 = 0;
    param = (ASN1_TYPE *)pcVar5;
  }
LAB_0054320c:
  if (local_2c == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((pbe_algs != (_STACK *)0x0) || (pbe_algs = sk_new(pbe_cmp), pbe_algs != (_STACK *)0x0)) &&
     (data = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"evp_pbe.c",0xee), st = pbe_algs,
     data != (int *)0x0)) {
    *data = iVar2;
    data[1] = (int)pass;
    data[2] = passlen;
    data[3] = (int)param;
    data[4] = (int)line;
    sk_push(st,data);
    return 1;
  }
  ERR_put_error(6,0xa0,0x41,"evp_pbe.c",0xfb);
  return 0;
}

