
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  int **ppiVar5;
  int *piVar6;
  EVP_PKEY *pEVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_30;
  int **local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int ***)PTR___stack_chk_guard_006a9ae8;
  iVar2 = 0;
  pEVar7 = pubkey;
  if (x == (X509 *)0x0) goto LAB_00580264;
  pEVar4 = pubkey;
  if ((pubkey == (EVP_PKEY *)0x0) && (pEVar4 = X509_get_pubkey(x), pEVar4 == (EVP_PKEY *)0x0)) {
    iVar2 = 0;
    goto LAB_00580264;
  }
  iVar2 = pEVar4->type;
  if (iVar2 == 0x74) {
    iVar10 = 0x412;
    iVar12 = 0x212;
    iVar11 = 0x112;
    iVar9 = 0x12;
LAB_00580240:
    local_30 = (*(code *)PTR_OBJ_obj2nid_006a712c)(x->sig_alg->algorithm);
  }
  else {
    if (0x74 < iVar2) {
      if (iVar2 == 0x198) {
        iVar10 = 0x458;
        iVar12 = 600;
        iVar11 = 0x158;
        iVar9 = 0x58;
      }
      else {
        if ((iVar2 < 0x198) || (1 < iVar2 - 0x32bU)) goto LAB_005802a0;
        iVar10 = 0x450;
        iVar12 = 0x250;
        iVar11 = 0x150;
        iVar9 = 0x50;
      }
      goto LAB_00580240;
    }
    if (iVar2 == 6) {
      iVar10 = 0x431;
      iVar12 = 0x231;
      iVar11 = 0x131;
      iVar9 = 0x31;
      goto LAB_00580240;
    }
    if (iVar2 != 0x1c) {
LAB_005802a0:
      iVar10 = 0x400;
      iVar12 = 0x200;
      iVar11 = 0x100;
      iVar9 = 0;
      goto LAB_00580240;
    }
    iVar10 = 0x444;
    iVar12 = 0x244;
    iVar11 = 0x144;
    iVar9 = 0x44;
    local_30 = (*(code *)PTR_OBJ_obj2nid_006a712c)(x->sig_alg->algorithm);
  }
  iVar2 = iVar9;
  if (local_30 != 0) {
    pEVar7 = (EVP_PKEY *)0x0;
    iVar3 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(local_30,0,&local_30);
    if ((iVar3 != 0) && (iVar2 = iVar12, local_30 != 0x43)) {
      if (local_30 < 0x44) {
        if ((local_30 == 6) || (iVar2 = iVar9, local_30 == 0x13)) {
          iVar2 = iVar11;
        }
      }
      else if ((local_30 != 0x74) && (iVar2 = iVar9, local_30 == 0x198)) {
        iVar2 = iVar10;
      }
    }
  }
  if (pubkey == (EVP_PKEY *)0x0) {
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar4);
  }
LAB_00580264:
  if (local_2c == *(int ***)puVar1) {
    return iVar2;
  }
  ppiVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar6 = *ppiVar5;
  piVar8 = (int *)pEVar7->type;
  iVar9 = *piVar6;
  iVar2 = iVar9 - *piVar8;
  if (iVar2 == 0) {
    if (iVar9 == 1) {
      iVar2 = X509_subject_name_cmp((X509 *)piVar6[1],(X509 *)piVar8[1]);
      return iVar2;
    }
    if (iVar9 == 2) {
      iVar2 = X509_CRL_cmp((X509_CRL *)piVar6[1],(X509_CRL *)piVar8[1]);
      return iVar2;
    }
    iVar2 = 0;
  }
  return iVar2;
}

