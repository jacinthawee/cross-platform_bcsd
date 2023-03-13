
X509_EXTENSION * __regparm3
do_ext_nconf(CONF *param_1_00,v3_ext_ctx *param_2_00,X509_EXTENSION *param_3,int param_1,
            char *param_2)

{
  X509V3_EXT_METHOD *method;
  int iVar1;
  ASN1_VALUE *val;
  ASN1_STRING *data;
  X509V3_EXT_S2I pXVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  int line;
  _STACK *local_30;
  uchar *local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_3 == (X509_EXTENSION *)0x0) {
    ERR_put_error(0x22,0x97,0x82,"v3_conf.c",0x7d);
    goto LAB_081676de;
  }
  method = X509V3_EXT_get_nid((int)param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    line = 0x81;
    iVar1 = 0x81;
LAB_0816781f:
    ERR_put_error(0x22,0x97,iVar1,"v3_conf.c",line);
    param_3 = (X509_EXTENSION *)0x0;
    goto LAB_081676de;
  }
  if (method->v2i == (X509V3_EXT_V2I)0x0) {
    pXVar2 = method->s2i;
    if (pXVar2 == (X509V3_EXT_S2I)0x0) {
      pXVar2 = (X509V3_EXT_S2I)method->r2i;
      if (pXVar2 == (X509V3_EXT_S2I)0x0) {
        ERR_put_error(0x22,0x97,0x67,"v3_conf.c",0xa2);
        pcVar3 = OBJ_nid2sn((int)param_3);
        ERR_add_error_data(2,"name=",pcVar3);
        param_3 = (X509_EXTENSION *)0x0;
        goto LAB_081676de;
      }
      if ((param_2_00->db == (void *)0x0) || (param_2_00->db_meth == (X509V3_CONF_METHOD *)0x0)) {
        line = 0x9b;
        iVar1 = 0x88;
        goto LAB_0816781f;
      }
    }
    val = (ASN1_VALUE *)(*pXVar2)(method,param_2_00,param_2);
  }
  else {
    if (*param_2 == '@') {
      local_30 = (_STACK *)NCONF_get_section(param_1_00,param_2 + 1);
    }
    else {
      local_30 = (_STACK *)X509V3_parse_list(param_2);
    }
    iVar1 = sk_num(local_30);
    if (iVar1 < 1) {
      ERR_put_error(0x22,0x97,0x69,"v3_conf.c",0x8c);
      pcVar3 = OBJ_nid2sn((int)param_3);
      ERR_add_error_data(4,"name=",pcVar3,",section=",param_2);
      param_3 = (X509_EXTENSION *)0x0;
      goto LAB_081676de;
    }
    val = (ASN1_VALUE *)(*method->v2i)(method,param_2_00,(stack_st_CONF_VALUE *)local_30);
    if (*param_2 != '@') {
      sk_pop_free(local_30,X509V3_conf_free);
    }
  }
  if (val == (ASN1_VALUE *)0x0) {
    param_3 = (X509_EXTENSION *)0x0;
    goto LAB_081676de;
  }
  if (method->it == (ASN1_ITEM *)0x0) {
    iVar1 = (*method->i2d)(val,(uchar **)0x0);
    local_28 = (uchar *)CRYPTO_malloc(iVar1,"v3_conf.c",0xc1);
    if (local_28 != (uchar *)0x0) {
      local_24 = local_28;
      (*method->i2d)(val,&local_24);
      goto LAB_0816767b;
    }
LAB_081677a0:
    param_3 = (X509_EXTENSION *)0x0;
    ERR_put_error(0x22,0x87,0x41,"v3_conf.c",0xd3);
  }
  else {
    local_28 = (uchar *)0x0;
    iVar1 = ASN1_item_i2d(val,&local_28,method->it);
    if (iVar1 < 0) goto LAB_081677a0;
LAB_0816767b:
    data = ASN1_STRING_type_new(4);
    if (data == (ASN1_STRING *)0x0) goto LAB_081677a0;
    data->data = local_28;
    data->length = iVar1;
    param_3 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,(int)param_3,param_1,data);
    if (param_3 == (X509_EXTENSION *)0x0) goto LAB_081677a0;
    ASN1_STRING_free(data);
  }
  if (method->it == (ASN1_ITEM *)0x0) {
    (*method->ext_free)(val);
  }
  else {
    ASN1_item_free(val,method->it);
  }
LAB_081676de:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

