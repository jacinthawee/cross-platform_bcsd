
undefined4 gost89_get_asn1_parameters(int *param_1,ASN1_TYPE *param_2)

{
  int *piVar1;
  size_t __n;
  int iVar2;
  size_t **ppsVar3;
  char *s;
  undefined4 uVar4;
  ASN1_OBJECT *o;
  int iVar5;
  int *piVar6;
  int iVar7;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = (int *)param_1[0x18];
  iVar2 = ASN1_TYPE_get(param_2);
  if (iVar2 != 0x10) {
    uVar4 = 0xffffffff;
    goto LAB_081dafd0;
  }
  local_24 = ((param_2->value).asn1_string)->data;
  ppsVar3 = (size_t **)d2i_GOST_CIPHER_PARAMS(0,&local_24,((param_2->value).asn1_string)->length);
  __n = **ppsVar3;
  if (__n != *(size_t *)(*param_1 + 0xc)) {
    GOST_CIPHER_PARAMS_free(ppsVar3);
    ERR_GOST_error(0x6c,0x6e,"gost_crypt.c",0x1e9);
    uVar4 = 0xffffffff;
    goto LAB_081dafd0;
  }
  iVar2 = OBJ_obj2nid((ASN1_OBJECT *)ppsVar3[1]);
  if ((iVar2 == 0) || (o = OBJ_nid2obj(iVar2), o == (ASN1_OBJECT *)0x0)) {
    s = (char *)get_gost_engine_param(0);
    if ((s != (char *)0x0) && (*s != '\0')) {
      iVar2 = OBJ_txt2nid(s);
      if (iVar2 != 0) goto LAB_081db010;
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
      goto LAB_081db05a;
    }
    piVar6 = (int *)(gost_cipher_list + 0xc);
    iVar5 = gost_cipher_list._16_4_;
    iVar7 = gost_cipher_list._12_4_;
  }
  else {
    iVar2 = OBJ_obj2nid(o);
LAB_081db010:
    if (gost_cipher_list._4_4_ == 0) {
LAB_081db044:
      ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
LAB_081db05a:
      GOST_CIPHER_PARAMS_free(ppsVar3);
      uVar4 = 0xffffffff;
      goto LAB_081dafd0;
    }
    piVar6 = (int *)gost_cipher_list;
    iVar7 = gost_cipher_list._0_4_;
    iVar5 = gost_cipher_list._4_4_;
    while (iVar2 != iVar7) {
      iVar5 = piVar6[4];
      if (iVar5 == 0) goto LAB_081db044;
      iVar7 = piVar6[3];
      piVar6 = piVar6 + 3;
    }
  }
  iVar2 = piVar6[2];
  *piVar1 = iVar7;
  piVar1[1] = 0;
  piVar1[2] = iVar2;
  gost_init(piVar1 + 3,iVar5);
  memcpy(param_1 + 4,(void *)(*ppsVar3)[2],__n);
  GOST_CIPHER_PARAMS_free(ppsVar3);
  uVar4 = 1;
LAB_081dafd0:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

