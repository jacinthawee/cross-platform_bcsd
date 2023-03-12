
X509_EXTENSION * __regparm3
v3_generic_extension(char *param_1_00,char *param_2_00,int param_3,int param_1,X509V3_CTX *param_2)

{
  char *pcVar1;
  ASN1_OBJECT *a;
  uchar *ptr;
  ASN1_TYPE *a_00;
  X509_EXTENSION *pXVar2;
  ASN1_STRING *data;
  int in_GS_OFFSET;
  int local_28;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = OBJ_txt2obj(param_1_00,0);
  if (a == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0x22,0x74,0x73,"v3_conf.c",0x10f);
    pcVar1 = ", name=";
LAB_081692f9:
    pXVar2 = (X509_EXTENSION *)0x0;
    data = (ASN1_STRING *)0x0;
    ERR_add_error_data(2,pcVar1 + 2,param_1_00);
  }
  else {
    if (param_1 != 1) {
      if (param_1 == 2) {
        local_24 = (uchar *)0x0;
        a_00 = ASN1_generate_v3(param_2_00,param_2);
        if (a_00 != (ASN1_TYPE *)0x0) {
          local_28 = i2d_ASN1_TYPE(a_00,&local_24);
          ASN1_TYPE_free(a_00);
          ptr = local_24;
          goto LAB_08169353;
        }
      }
LAB_081692d8:
      ERR_put_error(0x22,0x74,0x74,"v3_conf.c",0x11b);
      pcVar1 = ", value=";
      param_1_00 = param_2_00;
      goto LAB_081692f9;
    }
    ptr = string_to_hex(param_2_00,&local_28);
LAB_08169353:
    if (ptr == (uchar *)0x0) goto LAB_081692d8;
    data = ASN1_STRING_type_new(4);
    if (data == (ASN1_STRING *)0x0) {
      ERR_put_error(0x22,0x74,0x41,"v3_conf.c",0x122);
      ASN1_OBJECT_free(a);
      ASN1_STRING_free((ASN1_STRING *)0x0);
      pXVar2 = (X509_EXTENSION *)0x0;
      CRYPTO_free(ptr);
      goto LAB_0816931b;
    }
    data->data = ptr;
    data->length = local_28;
    pXVar2 = X509_EXTENSION_create_by_OBJ((X509_EXTENSION **)0x0,a,param_3,data);
  }
  ASN1_OBJECT_free(a);
  ASN1_STRING_free(data);
LAB_0816931b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pXVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

