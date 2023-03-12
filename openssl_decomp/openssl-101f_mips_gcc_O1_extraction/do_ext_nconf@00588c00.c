
X509_EXTENSION *
do_ext_nconf(CONF *param_1,v3_ext_ctx *param_2,X509_EXTENSION *param_3,int param_4,char *param_5)

{
  undefined *puVar1;
  X509V3_EXT_METHOD *method;
  stack_st_CONF_VALUE *values;
  int iVar2;
  void *pvVar3;
  ASN1_STRING *data;
  undefined4 uVar4;
  undefined4 uVar5;
  X509V3_EXT_S2I pXVar6;
  uchar *local_2c;
  uchar *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == (X509_EXTENSION *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x97,0x82,"v3_conf.c",0x7c);
    goto LAB_00588d84;
  }
  method = X509V3_EXT_get_nid((int)param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    uVar5 = 0x81;
    uVar4 = 0x81;
LAB_00588efc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x97,uVar5,"v3_conf.c",uVar4);
  }
  else {
    if (method->v2i == (X509V3_EXT_V2I)0x0) {
      pXVar6 = method->s2i;
      if (pXVar6 == (X509V3_EXT_S2I)0x0) {
        pXVar6 = (X509V3_EXT_S2I)method->r2i;
        uVar4 = 0xa3;
        if (pXVar6 == (X509V3_EXT_S2I)0x0) goto LAB_00588fa4;
        if ((param_2->db == (void *)0x0) || (param_2->db_meth == (X509V3_CONF_METHOD *)0x0)) {
          uVar5 = 0x88;
          uVar4 = 0x9c;
          goto LAB_00588efc;
        }
      }
      pvVar3 = (*pXVar6)(method,param_2,param_5);
    }
    else {
      if (*param_5 == '@') {
        values = NCONF_get_section(param_1,param_5 + 1);
      }
      else {
        values = X509V3_parse_list(param_5);
      }
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(values);
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x97,0x69,"v3_conf.c",0x8b);
        uVar4 = (*(code *)PTR_OBJ_nid2sn_006a819c)(param_3);
        (*(code *)PTR_ERR_add_error_data_006a9264)(4,"name=",uVar4,",section=",param_5);
        param_3 = (X509_EXTENSION *)0x0;
        goto LAB_00588d84;
      }
      pvVar3 = (*method->v2i)(method,param_2,values);
      if (*param_5 != '@') {
        (*(code *)PTR_sk_pop_free_006a8158)(values,PTR_X509V3_conf_free_006a8c38);
      }
    }
    if (pvVar3 != (void *)0x0) {
      if (method->it == (ASN1_ITEM_EXP *)0x0) {
        iVar2 = (*method->i2d)(pvVar3,(uchar **)0x0);
        local_2c = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"v3_conf.c",0xc1);
        if (local_2c != (uchar *)0x0) {
          local_28 = local_2c;
          (*method->i2d)(pvVar3,&local_28);
          goto LAB_00588d14;
        }
LAB_00588e6c:
        param_3 = (X509_EXTENSION *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x87,0x41,"v3_conf.c",0xd0);
      }
      else {
        local_2c = (uchar *)0x0;
        iVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pvVar3,&local_2c);
        if (iVar2 < 0) goto LAB_00588e6c;
LAB_00588d14:
        data = ASN1_STRING_type_new(4);
        if (data == (ASN1_STRING *)0x0) goto LAB_00588e6c;
        data->length = iVar2;
        data->data = local_2c;
        param_3 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,(int)param_3,param_4,data);
        if (param_3 == (X509_EXTENSION *)0x0) goto LAB_00588e6c;
        ASN1_STRING_free(data);
      }
      if (method->it == (ASN1_ITEM_EXP *)0x0) {
        (*method->ext_free)(pvVar3);
      }
      else {
        (*(code *)PTR_ASN1_item_free_006a977c)(pvVar3);
      }
      goto LAB_00588d84;
    }
  }
  param_3 = (X509_EXTENSION *)0x0;
LAB_00588d84:
  while (local_24 != *(int *)puVar1) {
    uVar4 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00588fa4:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x97,0x67,"v3_conf.c",uVar4);
    uVar4 = (*(code *)PTR_OBJ_nid2sn_006a819c)(param_3);
    (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",uVar4);
    param_3 = (X509_EXTENSION *)0x0;
  }
  return param_3;
}

