
ASN1_OBJECT *
v3_generic_extension(char *param_1,char *param_2,int param_3,int param_4,X509V3_CTX *param_5)

{
  ASN1_OBJECT *a;
  uchar *ptr;
  ASN1_OBJECT *data;
  ASN1_OBJECT *pAVar1;
  ASN1_TYPE *a_00;
  char *local_20;
  uchar *local_1c;
  
  a = OBJ_txt2obj(param_1,0);
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x74,0x73,"v3_conf.c",0x10f);
    ERR_add_error_data(2,"name=",param_1);
    data = a;
    pAVar1 = a;
    goto LAB_000cfefe;
  }
  if (param_4 == 1) {
    ptr = string_to_hex(param_2,(long *)&local_20);
LAB_000cff1c:
    if (ptr != (uchar *)0x0) {
      data = (ASN1_OBJECT *)ASN1_STRING_type_new(4);
      if (data == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0x22,0x74,0x41,"v3_conf.c",0x122);
        ASN1_OBJECT_free(a);
        ASN1_STRING_free((ASN1_STRING *)0x0);
        CRYPTO_free(ptr);
        return (ASN1_OBJECT *)0x0;
      }
      data->nid = (int)ptr;
      data->sn = local_20;
      pAVar1 = (ASN1_OBJECT *)
               X509_EXTENSION_create_by_OBJ
                         ((X509_EXTENSION **)0x0,a,param_3,(ASN1_OCTET_STRING *)data);
      goto LAB_000cfefe;
    }
  }
  else if (param_4 == 2) {
    local_1c = (uchar *)0x0;
    a_00 = ASN1_generate_v3(param_2,param_5);
    if (a_00 != (ASN1_TYPE *)0x0) {
      local_20 = (char *)i2d_ASN1_TYPE(a_00,&local_1c);
      ASN1_TYPE_free(a_00);
      ptr = local_1c;
      goto LAB_000cff1c;
    }
  }
  ERR_put_error(0x22,0x74,0x74,"v3_conf.c",0x11b);
  ERR_add_error_data(2,"value=",param_2);
  data = (ASN1_OBJECT *)0x0;
  pAVar1 = (ASN1_OBJECT *)0x0;
LAB_000cfefe:
  ASN1_OBJECT_free(a);
  ASN1_STRING_free((ASN1_STRING *)data);
  return pAVar1;
}

