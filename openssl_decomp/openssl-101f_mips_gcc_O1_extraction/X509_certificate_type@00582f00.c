
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  int iVar5;
  int **ppiVar6;
  int *piVar7;
  EVP_PKEY *pEVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int local_30;
  int **local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int ***)PTR___stack_chk_guard_006aabf0;
  uVar2 = 0;
  pEVar8 = pubkey;
  if (x == (X509 *)0x0) goto LAB_00583060;
  pEVar4 = pubkey;
  if ((pubkey == (EVP_PKEY *)0x0) && (pEVar4 = X509_get_pubkey(x), pEVar4 == (EVP_PKEY *)0x0)) {
    uVar2 = 0;
    goto LAB_00583060;
  }
  iVar3 = pEVar4->type;
  if (iVar3 == 0x74) {
    uVar11 = 0x412;
    uVar13 = 0x212;
    uVar12 = 0x112;
    uVar2 = 0x12;
LAB_00583020:
    local_30 = (*(code *)PTR_OBJ_obj2nid_006a822c)(x->sig_alg->algorithm);
    uVar10 = uVar2;
    if (local_30 == 0) goto LAB_0058303c;
LAB_00582fa8:
    pEVar8 = (EVP_PKEY *)0x0;
    iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(local_30,0,&local_30);
    uVar10 = uVar2;
    if ((iVar3 == 0) || (uVar10 = uVar13, local_30 == 0x43)) goto LAB_0058303c;
    if (0x43 < local_30) {
      if ((local_30 != 0x74) && (uVar10 = uVar2, local_30 == 0x198)) {
        uVar10 = uVar11;
      }
      goto LAB_0058303c;
    }
    uVar10 = uVar12;
    if ((local_30 == 6) || (local_30 == 0x13)) goto LAB_0058303c;
  }
  else {
    if (0x74 < iVar3) {
      if (iVar3 == 0x198) {
        uVar11 = 0x458;
        uVar13 = 600;
        uVar12 = 0x158;
        uVar2 = 0x58;
      }
      else {
        if ((iVar3 < 0x198) || (1 < iVar3 - 0x32bU)) goto LAB_0058309c;
        uVar11 = 0x450;
        uVar13 = 0x250;
        uVar12 = 0x150;
        uVar2 = 0x50;
      }
      goto LAB_00583020;
    }
    if (iVar3 == 6) {
      uVar11 = 0x431;
      uVar13 = 0x231;
      uVar12 = 0x131;
      uVar2 = 0x31;
      goto LAB_00583020;
    }
    if (iVar3 != 0x1c) {
LAB_0058309c:
      uVar11 = 0x400;
      uVar13 = 0x200;
      uVar12 = 0x100;
      uVar2 = 0;
      goto LAB_00583020;
    }
    uVar11 = 0x444;
    uVar13 = 0x244;
    uVar12 = 0x144;
    uVar2 = 0x44;
    local_30 = (*(code *)PTR_OBJ_obj2nid_006a822c)(x->sig_alg->algorithm);
    uVar10 = uVar2;
    if (local_30 != 0) goto LAB_00582fa8;
LAB_0058303c:
    uVar2 = uVar10;
  }
  iVar3 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(pEVar4);
  if (iVar3 < 0x81) {
    uVar2 = uVar2 | 0x1000;
  }
  if (pubkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar4);
  }
LAB_00583060:
  if (local_2c == *(int ***)puVar1) {
    return uVar2;
  }
  ppiVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar7 = *ppiVar6;
  piVar9 = (int *)pEVar8->type;
  iVar5 = *piVar7;
  iVar3 = iVar5 - *piVar9;
  if (iVar3 == 0) {
    if (iVar5 == 1) {
      iVar3 = X509_subject_name_cmp((X509 *)piVar7[1],(X509 *)piVar9[1]);
      return iVar3;
    }
    if (iVar5 == 2) {
      iVar3 = X509_CRL_cmp((X509_CRL *)piVar7[1],(X509_CRL *)piVar9[1]);
      return iVar3;
    }
    iVar3 = 0;
  }
  return iVar3;
}

