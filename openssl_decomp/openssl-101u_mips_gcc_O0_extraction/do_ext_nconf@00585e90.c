
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_3 == (X509_EXTENSION *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x97,0x82,"v3_conf.c",0x7d);
    goto LAB_00586014;
  }
  method = X509V3_EXT_get_nid((int)param_3);
  if (method == (X509V3_EXT_METHOD *)0x0) {
    uVar5 = 0x81;
    uVar4 = 0x81;
LAB_0058618c:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x97,uVar5,"v3_conf.c",uVar4);
  }
  else {
    if (method->v2i == (X509V3_EXT_V2I)0x0) {
      pXVar6 = method->s2i;
      if (pXVar6 == (X509V3_EXT_S2I)0x0) {
        pXVar6 = (X509V3_EXT_S2I)method->r2i;
        uVar4 = 0xa2;
        if (pXVar6 == (X509V3_EXT_S2I)0x0) goto LAB_00586234;
        if ((param_2->db == (void *)0x0) || (param_2->db_meth == (X509V3_CONF_METHOD *)0x0)) {
          uVar5 = 0x88;
          uVar4 = 0x9b;
          goto LAB_0058618c;
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
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(values);
      if (iVar2 < 1) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x97,0x69,"v3_conf.c",0x8c);
        uVar4 = (*(code *)PTR_OBJ_nid2sn_006a709c)(param_3);
        (*(code *)PTR_ERR_add_error_data_006a813c)(4,"name=",uVar4,",section=",param_5);
        param_3 = (X509_EXTENSION *)0x0;
        goto LAB_00586014;
      }
      pvVar3 = (*method->v2i)(method,param_2,values);
      if (*param_5 != '@') {
        (*(code *)PTR_sk_pop_free_006a7058)(values,PTR_X509V3_conf_free_006a7b4c);
      }
    }
    if (pvVar3 != (void *)0x0) {
      if (method->it == (ASN1_ITEM_EXP *)0x0) {
        iVar2 = (*method->i2d)(pvVar3,(uchar **)0x0);
        local_2c = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"v3_conf.c",0xc1);
        if (local_2c != (uchar *)0x0) {
          local_28 = local_2c;
          (*method->i2d)(pvVar3,&local_28);
          goto LAB_00585fa4;
        }
LAB_005860fc:
        param_3 = (X509_EXTENSION *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x87,0x41,"v3_conf.c",0xd3);
      }
      else {
        local_2c = (uchar *)0x0;
        iVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pvVar3,&local_2c);
        if (iVar2 < 0) goto LAB_005860fc;
LAB_00585fa4:
        data = ASN1_STRING_type_new(4);
        if (data == (ASN1_STRING *)0x0) goto LAB_005860fc;
        data->length = iVar2;
        data->data = local_2c;
        param_3 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,(int)param_3,param_4,data);
        if (param_3 == (X509_EXTENSION *)0x0) goto LAB_005860fc;
        ASN1_STRING_free(data);
      }
      if (method->it == (ASN1_ITEM_EXP *)0x0) {
        (*method->ext_free)(pvVar3);
      }
      else {
        (*(code *)PTR_ASN1_item_free_006a8658)(pvVar3);
      }
      goto LAB_00586014;
    }
  }
  param_3 = (X509_EXTENSION *)0x0;
LAB_00586014:
  while (local_24 != *(int *)puVar1) {
    uVar4 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00586234:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x97,0x67,"v3_conf.c",uVar4);
    uVar4 = (*(code *)PTR_OBJ_nid2sn_006a709c)(param_3);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",uVar4);
    param_3 = (X509_EXTENSION *)0x0;
  }
  return param_3;
}

