
X509_EXTENSION * X509V3_EXT_i2d(int ext_nid,int crit,void *ext_struc)

{
  undefined *puVar1;
  X509V3_EXT_METHOD *pXVar2;
  int iVar3;
  ASN1_STRING *data;
  X509_EXTENSION *pXVar4;
  stack_st_CONF_VALUE *psVar5;
  int iVar6;
  CONF *conf;
  char *x;
  uchar *local_2c;
  uchar *local_28;
  CONF *local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(CONF **)PTR___stack_chk_guard_006aabf0;
  pXVar2 = X509V3_EXT_get_nid(ext_nid);
  if (pXVar2 == (X509V3_EXT_METHOD *)0x0) {
    crit = 0x81;
    x = "v3_conf.c";
    ext_nid = (int)&DAT_00000088;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22);
    pXVar4 = (X509_EXTENSION *)0x0;
    goto LAB_0058952c;
  }
  if (pXVar2->it == (ASN1_ITEM_EXP *)0x0) {
    iVar3 = (*pXVar2->i2d)(ext_struc,(uchar **)0x0);
    local_2c = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,"v3_conf.c",0xc1);
    if (local_2c != (uchar *)0x0) {
      local_28 = local_2c;
      (*pXVar2->i2d)(ext_struc,&local_28);
      goto LAB_005894d0;
    }
  }
  else {
    local_2c = (uchar *)0x0;
    iVar3 = (*(code *)PTR_ASN1_item_i2d_006a979c)(ext_struc,&local_2c);
    if (-1 < iVar3) {
LAB_005894d0:
      data = ASN1_STRING_type_new(4);
      if (data != (ASN1_STRING *)0x0) {
        data->length = iVar3;
        data->data = local_2c;
        x = (char *)data;
        pXVar4 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,ext_nid,crit,data);
        if (pXVar4 != (X509_EXTENSION *)0x0) {
          ASN1_STRING_free(data);
          goto LAB_0058952c;
        }
      }
    }
  }
  x = "v3_conf.c";
  crit = (int)&DAT_00000041;
  ext_nid = 0x87;
  (*(code *)PTR_ERR_put_error_006a9030)(0x22);
  pXVar4 = (X509_EXTENSION *)0x0;
LAB_0058952c:
  if (local_24 == *(CONF **)puVar1) {
    return pXVar4;
  }
  conf = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  psVar5 = NCONF_get_section(conf,(char *)crit);
  if (psVar5 != (stack_st_CONF_VALUE *)0x0) {
    iVar3 = 0;
    if ((ASN1_STRING *)x == (ASN1_STRING *)0x0) {
      while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar5), iVar3 < iVar6) {
        iVar6 = (*(code *)PTR_sk_value_006a7f24)(psVar5,iVar3);
        pXVar4 = X509V3_EXT_nconf(conf,(X509V3_CTX *)ext_nid,*(char **)(iVar6 + 4),
                                  *(char **)(iVar6 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) {
          return (X509_EXTENSION *)0x0;
        }
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar4);
        iVar3 = iVar3 + 1;
      }
    }
    else {
      while( true ) {
        iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar5);
        if (iVar6 <= iVar3) break;
        iVar6 = (*(code *)PTR_sk_value_006a7f24)(psVar5,iVar3);
        pXVar4 = X509V3_EXT_nconf(conf,(X509V3_CTX *)ext_nid,*(char **)(iVar6 + 4),
                                  *(char **)(iVar6 + 8));
        if (pXVar4 == (X509_EXTENSION *)0x0) {
          return (X509_EXTENSION *)0x0;
        }
        X509v3_add_ext((stack_st_X509_EXTENSION **)x,pXVar4,-1);
        (*(code *)PTR_X509_EXTENSION_free_006a8268)(pXVar4);
        iVar3 = iVar3 + 1;
      }
    }
    return (X509_EXTENSION *)0x1;
  }
  return (X509_EXTENSION *)0x0;
}

