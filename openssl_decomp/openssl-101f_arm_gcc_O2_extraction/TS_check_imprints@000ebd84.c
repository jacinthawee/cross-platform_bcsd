
undefined4 TS_check_imprints(ASN1_OBJECT **param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  size_t sVar4;
  uchar *__s2;
  
  iVar1 = TS_TST_INFO_get_msg_imprint(param_4);
  ppAVar2 = (ASN1_OBJECT **)TS_MSG_IMPRINT_get_algo();
  if (((param_1 == (ASN1_OBJECT **)0x0) ||
      (((iVar3 = OBJ_cmp(*param_1,*ppAVar2), iVar3 == 0 &&
        ((param_1[1] == (ASN1_OBJECT *)0x0 ||
         (iVar3 = ASN1_TYPE_get((ASN1_TYPE *)param_1[1]), iVar3 == 5)))) &&
       ((ppAVar2[1] == (ASN1_OBJECT *)0x0 ||
        (iVar3 = ASN1_TYPE_get((ASN1_TYPE *)ppAVar2[1]), iVar3 == 5)))))) &&
     (sVar4 = ASN1_STRING_length(*(ASN1_STRING **)(iVar1 + 4)), sVar4 == param_3)) {
    __s2 = ASN1_STRING_data(*(ASN1_STRING **)(iVar1 + 4));
    iVar1 = memcmp(param_2,__s2,param_3);
    if (iVar1 == 0) {
      return 1;
    }
  }
  ERR_put_error(0x2f,100,0x67,"ts_rsp_verify.c",0x296);
  return 0;
}

