
X509_EXTENSION *
v3_generic_extension(undefined4 param_1,char *param_2,int param_3,int param_4,X509V3_CTX *param_5)

{
  undefined *puVar1;
  ASN1_OBJECT *obj;
  uchar *puVar2;
  ASN1_TYPE *pAVar3;
  CONF *conf;
  char *section;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar4;
  int local_2c;
  uchar *local_28;
  CONF *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(CONF **)PTR___stack_chk_guard_006aabf0;
  obj = (ASN1_OBJECT *)(*(code *)PTR_OBJ_txt2obj_006a8100)(param_1,0);
  if (obj == (ASN1_OBJECT *)0x0) {
    pXVar4 = (X509_EXTENSION *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x74,0x73,"v3_conf.c",0x10f);
    section = "name=";
    data = (ASN1_STRING *)0x0;
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",param_1);
  }
  else {
    if (param_4 == 1) {
      puVar2 = string_to_hex(param_2,&local_2c);
LAB_00588a5c:
      if (puVar2 != (uchar *)0x0) {
        data = ASN1_STRING_type_new(4);
        if (data == (ASN1_STRING *)0x0) {
          section = &DAT_00000074;
          (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x74,0x41,"v3_conf.c",0x122);
          (*(code *)PTR_ASN1_OBJECT_free_006a8104)(obj);
          ASN1_STRING_free((ASN1_STRING *)0x0);
          pXVar4 = (X509_EXTENSION *)0x0;
          (*(code *)PTR_CRYPTO_free_006a7f88)(puVar2);
          goto LAB_00588a0c;
        }
        data->data = puVar2;
        data->length = local_2c;
        section = (char *)obj;
        pXVar4 = X509_EXTENSION_create_by_OBJ((X509_EXTENSION **)0x0,obj,param_3,data);
        goto LAB_005889ec;
      }
    }
    else if (param_4 == 2) {
      local_28 = (uchar *)0x0;
      pAVar3 = ASN1_generate_v3(param_2,param_5);
      if (pAVar3 != (ASN1_TYPE *)0x0) {
        local_2c = (*(code *)PTR_i2d_ASN1_TYPE_006a85a8)(pAVar3,&local_28);
        (*(code *)PTR_ASN1_TYPE_free_006a8598)(pAVar3);
        puVar2 = local_28;
        goto LAB_00588a5c;
      }
    }
    pXVar4 = (X509_EXTENSION *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x74,0x74,"v3_conf.c",0x11b);
    section = "value=";
    data = (ASN1_STRING *)0x0;
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"value=",param_2);
  }
LAB_005889ec:
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(obj);
  ASN1_STRING_free(data);
LAB_00588a0c:
  if (local_24 == *(CONF **)puVar1) {
    return pXVar4;
  }
  conf = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pXVar4 = (X509_EXTENSION *)NCONF_get_section(conf,section);
  return pXVar4;
}

