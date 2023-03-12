
X509_ALGOR * PKCS5_pbe_set(int alg,int iter,uchar *salt,int saltlen)

{
  undefined *puVar1;
  int *piVar2;
  uint uVar3;
  X509_ALGOR *pXVar4;
  ASN1_STRING **val;
  int iVar5;
  undefined4 uVar6;
  uchar *puVar7;
  undefined1 *aobj;
  ASN1_STRING *local_30;
  int local_2c;
  long v;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pXVar4 = X509_ALGOR_new();
  if (pXVar4 == (X509_ALGOR *)0x0) {
    aobj = &DAT_000000ca;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xca,0x41,"p5_pbe.c",0x86);
    pXVar4 = (X509_ALGOR *)0x0;
    goto LAB_005693e0;
  }
  local_30 = (ASN1_STRING *)0x0;
  val = (ASN1_STRING **)ASN1_item_new((ASN1_ITEM *)PBEPARAM_it);
  if (val == (ASN1_STRING **)0x0) {
    aobj = (undefined1 *)0xd7;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd7,0x41,"p5_pbe.c",0x56);
  }
  else {
    v = 0x800;
    if (0 < iter) {
      v = iter;
    }
    iVar5 = ASN1_INTEGER_set(val[1],v);
    if (iVar5 == 0) {
      uVar6 = 0x5c;
LAB_0056938c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xd7,0x41,"p5_pbe.c",uVar6);
    }
    else {
      if (saltlen == 0) {
        saltlen = 8;
      }
      iVar5 = ASN1_STRING_set(*val,(void *)0x0,saltlen);
      if (iVar5 == 0) {
        uVar6 = 0x62;
        goto LAB_0056938c;
      }
      puVar7 = ASN1_STRING_data(*val);
      if (salt != (uchar *)0x0) {
        (*(code *)PTR_memcpy_006a9aec)(puVar7,salt,saltlen);
LAB_00569444:
        iVar5 = (*(code *)PTR_ASN1_item_pack_006a8df4)(val,PBEPARAM_it,&local_30);
        if (iVar5 != 0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
          aobj = (undefined1 *)(*(code *)PTR_OBJ_nid2obj_006a7140)(alg);
          iVar5 = X509_ALGOR_set0(pXVar4,(ASN1_OBJECT *)aobj,0x10,local_30);
          if (iVar5 != 0) goto LAB_005693e0;
          goto LAB_005693b4;
        }
        uVar6 = 0x6c;
        goto LAB_0056938c;
      }
      iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(puVar7,saltlen);
      if (0 < iVar5) goto LAB_00569444;
    }
    aobj = PBEPARAM_it;
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBEPARAM_it);
  }
LAB_005693b4:
  if (local_30 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_30);
  }
  X509_ALGOR_free(pXVar4);
  pXVar4 = (X509_ALGOR *)0x0;
LAB_005693e0:
  if (local_2c == *(int *)puVar1) {
    return pXVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar2 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (uint)PBE2PARAM_it[0];
  if (PBE2PARAM_it._16_4_ == 0) {
    if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar4 = (X509_ALGOR *)(*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar3])();
      return pXVar4;
    }
  }
  else if (uVar3 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar4 = (X509_ALGOR *)(*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar3])();
    return pXVar4;
  }
  if (piVar2 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return (X509_ALGOR *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(X509_ALGOR **)(*piVar2 + (int)*(char ***)((int)aobj + 4));
}

