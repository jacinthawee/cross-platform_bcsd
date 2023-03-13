
EC_KEY * d2i_ECParameters(EC_KEY **key,uchar **in,long len)

{
  undefined *puVar1;
  undefined *puVar2;
  uchar *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  EC_KEY **ppEVar8;
  EC_GROUP *pEVar9;
  undefined1 *puVar10;
  EC_POINT *p;
  undefined4 uVar11;
  EC_KEY *pEVar12;
  uchar *local_28;
  EC_KEY **local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(EC_KEY ***)PTR___stack_chk_guard_006a9ae8;
  if ((in == (uchar **)0x0) || (puVar3 = *in, puVar3 == (uchar *)0x0)) {
    len = 0x43;
    uVar6 = 0x4d6;
LAB_00508a7c:
    puVar10 = &DAT_00000090;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x90,len,"ec_asn1.c",uVar6);
    pEVar12 = (EC_KEY *)0x0;
  }
  else {
    if ((key == (EC_KEY **)0x0) || (pEVar12 = *key, pEVar12 == (EC_KEY *)0x0)) {
      pEVar12 = EC_KEY_new();
      if (pEVar12 == (EC_KEY *)0x0) {
        len = 0x41;
        uVar6 = 0x4dc;
        goto LAB_00508a7c;
      }
      puVar3 = *in;
    }
    local_28 = puVar3;
    piVar4 = (int *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,&local_28,len,ECPKPARAMETERS_it);
    if (piVar4 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x91,0x75,"ec_asn1.c",0x3d0);
      (*(code *)PTR_ASN1_item_free_006a8658)(0,ECPKPARAMETERS_it);
    }
    else {
      iVar5 = *piVar4;
      if (iVar5 == 0) {
        iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(piVar4[1]);
        pEVar9 = EC_GROUP_new_by_curve_name(iVar5);
        if (pEVar9 != (EC_GROUP *)0x0) {
          EC_GROUP_set_asn1_flag(pEVar9,1);
LAB_005089a0:
          if (*(EC_GROUP **)(pEVar12 + 4) != (EC_GROUP *)0x0) {
            EC_GROUP_clear_free(*(EC_GROUP **)(pEVar12 + 4));
          }
          puVar1 = PTR_ASN1_item_free_006a8658;
          puVar10 = ECPKPARAMETERS_it;
          *(EC_GROUP **)(pEVar12 + 4) = pEVar9;
          (*(code *)puVar1)(piVar4);
          *in = local_28;
          if (key != (EC_KEY **)0x0) {
            *key = pEVar12;
          }
          goto LAB_005089e4;
        }
        uVar11 = 0x77;
        uVar6 = 0x3b1;
LAB_005088c4:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x9e,uVar11,"ec_asn1.c",uVar6);
      }
      else {
        if (iVar5 == 1) {
          pEVar9 = (EC_GROUP *)ec_asn1_parameters2group(piVar4[1]);
          if (pEVar9 != (EC_GROUP *)0x0) {
            EC_GROUP_set_asn1_flag(pEVar9,0);
            goto LAB_005089a0;
          }
          uVar11 = 0x10;
          uVar6 = 0x3b9;
          goto LAB_005088c4;
        }
        if (iVar5 != 2) {
          uVar11 = 0x73;
          uVar6 = 0x3c0;
          goto LAB_005088c4;
        }
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x91,0x7f,"ec_asn1.c",0x3d6);
      (*(code *)PTR_ASN1_item_free_006a8658)(piVar4,ECPKPARAMETERS_it);
    }
    len = 0x10;
    puVar10 = &DAT_00000090;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x90,0x10,"ec_asn1.c",0x4e3);
    if ((key == (EC_KEY **)0x0) || (*key != pEVar12)) {
      EC_KEY_free(pEVar12);
      pEVar12 = (EC_KEY *)0x0;
    }
    else {
      pEVar12 = (EC_KEY *)0x0;
    }
  }
LAB_005089e4:
  if (local_24 == *(EC_KEY ***)puVar2) {
    return pEVar12;
  }
  ppEVar8 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((ppEVar8 == (EC_KEY **)0x0) || (pEVar12 = *ppEVar8, pEVar12 == (EC_KEY *)0x0)) ||
     (pEVar9 = *(EC_GROUP **)(pEVar12 + 4), pEVar9 == (EC_GROUP *)0x0)) {
    uVar11 = 0x43;
    uVar6 = 0x4f7;
  }
  else {
    p = *(EC_POINT **)(pEVar12 + 8);
    if (p == (EC_POINT *)0x0) {
      p = EC_POINT_new(pEVar9);
      *(EC_POINT **)(pEVar12 + 8) = p;
      if (p == (EC_POINT *)0x0) {
        uVar11 = 0x41;
        uVar6 = 0x4fd;
        goto LAB_00508c00;
      }
      pEVar9 = *(EC_GROUP **)(pEVar12 + 4);
    }
    iVar5 = EC_POINT_oct2point(pEVar9,p,*(byte **)puVar10,len,(BN_CTX *)0x0);
    if (iVar5 != 0) {
      pbVar7 = *(byte **)puVar10;
      *(uint *)(pEVar12 + 0x14) = *pbVar7 & 0xfe;
      *(byte **)puVar10 = pbVar7 + len;
      return pEVar12;
    }
    uVar11 = 0x10;
    uVar6 = 0x501;
  }
LAB_00508c00:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x98,uVar11,"ec_asn1.c",uVar6);
  return (EC_KEY *)0x0;
}

