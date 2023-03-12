
_STACK * v2i_AUTHORITY_INFO_ACCESS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK *st;
  void *pvVar1;
  ASN1_OBJECT **data;
  char *pcVar2;
  GENERAL_NAME *pGVar3;
  char *pcVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  size_t __n;
  int in_GS_OFFSET;
  int local_40;
  CONF_VALUE local_2c;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0x22,0x8b,0x41,"v3_info.c",0x90);
    st = (_STACK *)0x0;
  }
  else {
    for (local_40 = 0; iVar6 = sk_num(param_3), local_40 < iVar6; local_40 = local_40 + 1) {
      pvVar1 = sk_value(param_3,local_40);
      data = (ASN1_OBJECT **)ASN1_item_new((ASN1_ITEM *)ACCESS_DESCRIPTION_it);
      if ((data == (ASN1_OBJECT **)0x0) || (iVar6 = sk_push(st,data), iVar6 == 0)) {
        iVar6 = 0x97;
LAB_081750d0:
        ERR_put_error(0x22,0x8b,0x41,"v3_info.c",iVar6);
LAB_081750e6:
        sk_pop_free(st,ACCESS_DESCRIPTION_free);
        st = (_STACK *)0x0;
        break;
      }
      pcVar4 = *(char **)((int)pvVar1 + 4);
      pcVar2 = strchr(pcVar4,0x3b);
      if (pcVar2 == (char *)0x0) {
        ERR_put_error(0x22,0x8b,0x8f,"v3_info.c",0x9c);
        goto LAB_081750e6;
      }
      local_2c.name = pcVar2 + 1;
      local_2c.value = *(char **)((int)pvVar1 + 8);
      __n = (int)pcVar2 - (int)pcVar4;
      pGVar3 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)data[1],param_1,param_2,&local_2c,0);
      if (pGVar3 == (GENERAL_NAME *)0x0) goto LAB_081750e6;
      pcVar4 = (char *)CRYPTO_malloc(__n + 1,"v3_info.c",0xa4);
      if (pcVar4 == (char *)0x0) {
        iVar6 = 0xa5;
        goto LAB_081750d0;
      }
      strncpy(pcVar4,*(char **)((int)pvVar1 + 4),__n);
      pcVar4[__n] = '\0';
      pAVar5 = OBJ_txt2obj(pcVar4,0);
      *data = pAVar5;
      if (pAVar5 == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x22,0x8b,0x77,"v3_info.c",0xac);
        ERR_add_error_data(2,"value=",pcVar4);
        CRYPTO_free(pcVar4);
        goto LAB_081750e6;
      }
      CRYPTO_free(pcVar4);
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return st;
}

