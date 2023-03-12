
undefined4 gost89_get_asn1_parameters(int *param_1,ASN1_TYPE *param_2)

{
  int *piVar1;
  int iVar2;
  size_t **ppsVar3;
  char *s;
  ASN1_OBJECT *o;
  undefined *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  size_t __n;
  uchar *local_24 [2];
  
  piVar8 = (int *)param_1[0x18];
  iVar2 = ASN1_TYPE_get(param_2);
  if (iVar2 != 0x10) {
    return 0xffffffff;
  }
  local_24[0] = ((param_2->value).asn1_string)->data;
  ppsVar3 = (size_t **)d2i_GOST_CIPHER_PARAMS(0,local_24,((param_2->value).asn1_string)->length);
  __n = *(size_t *)(*param_1 + 0xc);
  if (__n != **ppsVar3) {
    GOST_CIPHER_PARAMS_free();
    ERR_GOST_error(0x6c,0x6e,"gost_crypt.c",0x1e9);
    return 0xffffffff;
  }
  iVar2 = OBJ_obj2nid((ASN1_OBJECT *)ppsVar3[1]);
  if ((iVar2 == 0) || (o = OBJ_nid2obj(iVar2), o == (ASN1_OBJECT *)0x0)) {
    s = (char *)get_gost_engine_param(0);
    if ((s == (char *)0x0) || (*s == '\0')) {
      puVar7 = &DAT_00195a9c;
      iVar2 = DAT_00195a9c;
      puVar4 = PTR_Gost28147_CryptoProParamSetA_00195aa0;
      goto LAB_0011bfae;
    }
    iVar2 = OBJ_txt2nid(s);
    if (iVar2 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
      goto LAB_0011bf9a;
    }
  }
  else {
    iVar2 = OBJ_obj2nid(o);
  }
  puVar7 = &gost_cipher_list;
  if (PTR_GostR3411_94_CryptoProParamSet_00195a94 != (undefined *)0x0) {
    puVar4 = PTR_GostR3411_94_CryptoProParamSet_00195a94;
    puVar5 = puVar7;
    if (gost_cipher_list != iVar2) {
      do {
        puVar4 = (undefined *)puVar5[4];
        puVar7 = puVar5 + 3;
        if (puVar4 == (undefined *)0x0) goto LAB_0011bf88;
        piVar1 = puVar5 + 3;
        puVar5 = puVar7;
      } while (*piVar1 != iVar2);
      if (puVar7 == (undefined4 *)0x0) goto LAB_0011bf9a;
    }
LAB_0011bfae:
    iVar6 = puVar7[2];
    *piVar8 = iVar2;
    piVar8[1] = 0;
    piVar8[2] = iVar6;
    gost_init(piVar8 + 3,puVar4);
    memcpy(param_1 + 4,(void *)(*ppsVar3)[2],__n);
    GOST_CIPHER_PARAMS_free(ppsVar3);
    return 1;
  }
LAB_0011bf88:
  ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
LAB_0011bf9a:
  GOST_CIPHER_PARAMS_free(ppsVar3);
  return 0xffffffff;
}

