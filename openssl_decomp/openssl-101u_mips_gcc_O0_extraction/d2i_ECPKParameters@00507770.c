
EC_GROUP * d2i_ECPKParameters(EC_GROUP **param_1,uchar **in,long len)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  EC_GROUP *pEVar8;
  uchar *local_28;
  EC_GROUP *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_28 = *in;
  local_24 = *(EC_GROUP **)PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,&local_28,len,ECPKPARAMETERS_it);
  if (piVar2 == (int *)0x0) {
    pEVar8 = (EC_GROUP *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x91,0x75,"ec_asn1.c",0x3d0);
    puVar6 = ECPKPARAMETERS_it;
    (*(code *)PTR_ASN1_item_free_006a8658)(0,ECPKPARAMETERS_it);
  }
  else {
    iVar3 = *piVar2;
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(piVar2[1]);
      pEVar8 = EC_GROUP_new_by_curve_name(iVar3);
      if (pEVar8 == (EC_GROUP *)0x0) {
        uVar7 = 0x77;
        uVar4 = 0x3b1;
        goto LAB_0050780c;
      }
      EC_GROUP_set_asn1_flag(pEVar8,1);
LAB_005078d4:
      if (param_1 != (EC_GROUP **)0x0) {
        if (*param_1 != (EC_GROUP *)0x0) {
          EC_GROUP_clear_free(*param_1);
        }
        *param_1 = pEVar8;
      }
      puVar6 = ECPKPARAMETERS_it;
      (*(code *)PTR_ASN1_item_free_006a8658)(piVar2,ECPKPARAMETERS_it);
      *in = local_28;
    }
    else {
      if (iVar3 == 1) {
        pEVar8 = (EC_GROUP *)ec_asn1_parameters2group(piVar2[1]);
        if (pEVar8 != (EC_GROUP *)0x0) {
          EC_GROUP_set_asn1_flag(pEVar8,0);
          goto LAB_005078d4;
        }
        uVar7 = 0x10;
        uVar4 = 0x3b9;
LAB_0050780c:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9e,uVar7,"ec_asn1.c",uVar4);
      }
      else if (iVar3 != 2) {
        uVar7 = 0x73;
        uVar4 = 0x3c0;
        goto LAB_0050780c;
      }
      pEVar8 = (EC_GROUP *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x91,0x7f,"ec_asn1.c",0x3d6);
      puVar6 = ECPKPARAMETERS_it;
      (*(code *)PTR_ASN1_item_free_006a8658)(piVar2,ECPKPARAMETERS_it);
    }
  }
  if (local_24 == *(EC_GROUP **)puVar1) {
    return pEVar8;
  }
  pEVar8 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar5 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(ECPKPARAMETERS_it);
  if (puVar5 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9c,0x41,"ec_asn1.c",0x28d);
    goto LAB_00507abc;
  }
  iVar3 = EC_GROUP_get_asn1_flag(pEVar8);
  if (iVar3 == 0) {
    *puVar5 = 1;
    iVar3 = ec_asn1_group2parameters_constprop_3(pEVar8);
    puVar5[1] = iVar3;
joined_r0x00507b6c:
    if (iVar3 != 0) {
      pEVar8 = (EC_GROUP *)(*(code *)PTR_ASN1_item_i2d_006a8678)(puVar5,puVar6,ECPKPARAMETERS_it);
      if (pEVar8 != (EC_GROUP *)0x0) {
        (*(code *)PTR_ASN1_item_free_006a8658)(puVar5,ECPKPARAMETERS_it);
        return pEVar8;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbf,0x79,"ec_asn1.c",0x3ee);
      (*(code *)PTR_ASN1_item_free_006a8658)(puVar5,ECPKPARAMETERS_it);
      return (EC_GROUP *)0x0;
    }
  }
  else {
    iVar3 = EC_GROUP_get_curve_name(pEVar8);
    puVar1 = PTR_OBJ_nid2obj_006a7140;
    if (iVar3 != 0) {
      *puVar5 = 0;
      iVar3 = (*(code *)puVar1)(iVar3);
      puVar5[1] = iVar3;
      goto joined_r0x00507b6c;
    }
  }
  (*(code *)PTR_ASN1_item_free_006a8658)(puVar5,ECPKPARAMETERS_it);
LAB_00507abc:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbf,0x78,"ec_asn1.c",0x3ea);
  return (EC_GROUP *)0x0;
}

