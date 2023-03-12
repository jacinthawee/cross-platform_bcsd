
/* WARNING: Type propagation algorithm not settling */

stack_st_CONF_VALUE *
i2v_GENERAL_NAME(X509V3_EXT_METHOD *method,GENERAL_NAME *gen,stack_st_CONF_VALUE *ret)

{
  undefined2 uVar1;
  undefined *puVar2;
  GENERAL_NAME *gen_00;
  int iVar3;
  stack_st_CONF_VALUE *psVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  X509V3_EXT_METHOD *method_00;
  char *value;
  int iVar6;
  undefined2 *puVar7;
  undefined *puVar8;
  BUF_MEM *pBVar9;
  undefined local_134 [16];
  GENERAL_NAME local_124 [32];
  X509V3_EXT_METHOD *local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(X509V3_EXT_METHOD **)PTR___stack_chk_guard_006a9ae8;
  value = (char *)gen;
  psVar4 = ret;
  local_134._0_4_ = ret;
  switch(gen->type) {
  case 0:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = "<unsupported>";
    X509V3_add_value("othername","<unsupported>",(stack_st_CONF_VALUE **)psVar4);
    break;
  case 1:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = (char *)((gen->d).rfc822Name)->data;
    X509V3_add_value_uchar("email",(uchar *)value,(stack_st_CONF_VALUE **)psVar4);
    break;
  case 2:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = (char *)((gen->d).rfc822Name)->data;
    X509V3_add_value_uchar("DNS",(uchar *)value,(stack_st_CONF_VALUE **)psVar4);
    break;
  case 3:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = "<unsupported>";
    X509V3_add_value("X400Name","<unsupported>",(stack_st_CONF_VALUE **)psVar4);
    break;
  case 4:
    value = (char *)local_124;
    X509_NAME_oneline((gen->d).directoryName,value,0x100);
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    X509V3_add_value("DirName",value,(stack_st_CONF_VALUE **)psVar4);
    break;
  case 5:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = "<unsupported>";
    X509V3_add_value("EdiPartyName","<unsupported>",(stack_st_CONF_VALUE **)psVar4);
    break;
  case 6:
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    value = (char *)((gen->d).rfc822Name)->data;
    X509V3_add_value_uchar("URI",(uchar *)value,(stack_st_CONF_VALUE **)psVar4);
    break;
  case 7:
    psVar5 = ((gen->d).directoryName)->entries;
    pBVar9 = ((gen->d).directoryName)->bytes;
    if (psVar5 == (stack_st_X509_NAME_ENTRY *)0x4) {
      (*(code *)PTR_BIO_snprintf_006a6f60)
                (local_124,0x100,"%d.%d.%d.%d",*(undefined *)&pBVar9->length,
                 *(undefined *)((int)&pBVar9->length + 1),*(undefined *)((int)&pBVar9->length + 2),
                 *(undefined *)((int)&pBVar9->length + 3));
    }
    else {
      if (psVar5 != (stack_st_X509_NAME_ENTRY *)0x10) {
        psVar4 = (stack_st_CONF_VALUE *)local_134;
        value = "<invalid>";
        X509V3_add_value("IP Address","<invalid>",(stack_st_CONF_VALUE **)psVar4);
        break;
      }
      local_124[0].type._0_1_ = 0;
      puVar8 = local_134 + 8;
      (*(code *)PTR_BIO_snprintf_006a6f60)(puVar8,5,&DAT_0066e3a4,*(undefined2 *)&pBVar9->length);
      puVar7 = (undefined2 *)((int)&pBVar9->length + 2);
      (*(code *)PTR___strcat_chk_006a9b24)(local_124,puVar8,0x100);
      do {
        (*(code *)PTR___strcat_chk_006a9b24)(local_124,":",0x100);
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        (*(code *)PTR_BIO_snprintf_006a6f60)(puVar8,5,&DAT_0066e3a4,uVar1);
        (*(code *)PTR___strcat_chk_006a9b24)(local_124,puVar8,0x100);
      } while ((char **)puVar7 != &pBVar9[1].data);
    }
    value = (char *)local_124;
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    X509V3_add_value("IP Address",value,(stack_st_CONF_VALUE **)psVar4);
    break;
  case 8:
    value = (char *)local_124;
    (*(code *)PTR_i2t_ASN1_OBJECT_006a8c48)(value,0x100,(gen->d).ptr);
    psVar4 = (stack_st_CONF_VALUE *)local_134;
    X509V3_add_value("Registered ID",value,(stack_st_CONF_VALUE **)psVar4);
  }
  if (local_24 == *(X509V3_EXT_METHOD **)puVar2) {
    return local_134._0_4_;
  }
  method_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = 0;
  while( true ) {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(value);
    if (iVar3 <= iVar6) break;
    gen_00 = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a6e24)(value,iVar6);
    psVar4 = i2v_GENERAL_NAME(method_00,gen_00,psVar4);
    iVar6 = iVar6 + 1;
  }
  if (psVar4 == (stack_st_CONF_VALUE *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0058de44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    psVar4 = (stack_st_CONF_VALUE *)(*(code *)PTR_sk_new_null_006a6fa4)();
    return psVar4;
  }
  return psVar4;
}

