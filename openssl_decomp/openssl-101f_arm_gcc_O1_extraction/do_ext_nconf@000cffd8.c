
X509_EXTENSION *
do_ext_nconf(CONF *param_1,v3_ext_ctx *param_2,int param_3,int param_4,char *param_5)

{
  X509V3_EXT_METHOD *method;
  _STACK *st;
  int iVar1;
  ASN1_VALUE *val;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar2;
  char *pcVar3;
  uchar *local_28;
  uchar *local_24 [2];
  
  if (param_3 == 0) {
    ERR_put_error(0x22,0x97,0x82,"v3_conf.c",0x7c);
    return (X509_EXTENSION *)0x0;
  }
  method = X509V3_EXT_get_nid(param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x97,0x81,"v3_conf.c",0x81);
    return (X509_EXTENSION *)0x0;
  }
  if (method->v2i == (X509V3_EXT_V2I)0x0) {
    if (method->s2i == (X509V3_EXT_S2I)0x0) {
      if (method->r2i == (X509V3_EXT_R2I)0x0) {
        ERR_put_error(0x22,0x97,0x67,"v3_conf.c",0xa3);
        pcVar3 = OBJ_nid2sn(param_3);
        ERR_add_error_data(2,"name=",pcVar3);
        return (X509_EXTENSION *)0x0;
      }
      if ((param_2->db == (void *)0x0) || (param_2->db_meth == (X509V3_CONF_METHOD *)0x0)) {
        ERR_put_error(0x22,0x97,0x88,"v3_conf.c",0x9c);
        return (X509_EXTENSION *)0x0;
      }
      val = (ASN1_VALUE *)(*method->r2i)(method,param_2,param_5);
    }
    else {
      val = (ASN1_VALUE *)(*method->s2i)(method,param_2,param_5);
    }
  }
  else {
    if (*param_5 == '@') {
      st = (_STACK *)NCONF_get_section(param_1,param_5 + 1);
    }
    else {
      st = (_STACK *)X509V3_parse_list(param_5);
    }
    iVar1 = sk_num(st);
    if (iVar1 < 1) {
      ERR_put_error(0x22,0x97,0x69,"v3_conf.c",0x8b);
      pcVar3 = OBJ_nid2sn(param_3);
      ERR_add_error_data(4,"name=",pcVar3,",section=",param_5);
      return (X509_EXTENSION *)0x0;
    }
    val = (ASN1_VALUE *)(*method->v2i)(method,param_2,(stack_st_CONF_VALUE *)st);
    if (*param_5 != '@') {
      sk_pop_free(st,X509V3_conf_free + 1);
    }
  }
  if (val == (ASN1_VALUE *)0x0) {
    return (X509_EXTENSION *)0x0;
  }
  if (method->it == (ASN1_ITEM *)0x0) {
    iVar1 = (*method->i2d)(val,(uchar **)0x0);
    local_28 = (uchar *)CRYPTO_malloc(iVar1,"v3_conf.c",0xc1);
    if (local_28 != (uchar *)0x0) {
      local_24[0] = local_28;
      (*method->i2d)(val,local_24);
      goto LAB_000d005a;
    }
  }
  else {
    local_28 = (uchar *)0x0;
    iVar1 = ASN1_item_i2d(val,&local_28,method->it);
    if (-1 < iVar1) {
LAB_000d005a:
      data = ASN1_STRING_type_new(4);
      if (data != (ASN1_STRING *)0x0) {
        data->length = iVar1;
        data->data = local_28;
        pXVar2 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,param_3,param_4,data);
        if (pXVar2 != (X509_EXTENSION *)0x0) {
          ASN1_STRING_free(data);
          goto LAB_000d0086;
        }
      }
    }
  }
  pXVar2 = (X509_EXTENSION *)0x0;
  ERR_put_error(0x22,0x87,0x41,"v3_conf.c",0xd0);
LAB_000d0086:
  if (method->it != (ASN1_ITEM *)0x0) {
    ASN1_item_free(val,method->it);
    return pXVar2;
  }
  (*method->ext_free)(val);
  return pXVar2;
}

