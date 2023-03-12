
int cms_SignedData_init_bio(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_1);
  if (iVar1 != 0x16) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    return 0;
  }
  piVar6 = (int *)param_1[1];
  if (piVar6 != (int *)0x0) {
    iVar1 = 0;
    if (*(int *)(piVar6[2] + 8) != 0) {
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[3]);
      if (0 < iVar4) {
        do {
          piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(piVar6[3],iVar1);
          iVar4 = *piVar5;
          if (iVar4 == 4) {
            if (*piVar6 < 5) {
              *piVar6 = 5;
            }
          }
          else if (iVar4 == 3) {
            if (*piVar6 < 4) {
              *piVar6 = 4;
            }
          }
          else if ((iVar4 == 2) && (*piVar6 < 3)) {
            *piVar6 = 3;
          }
          iVar1 = iVar1 + 1;
          iVar4 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[3]);
        } while (iVar1 < iVar4);
      }
      iVar1 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[4]);
        iVar2 = iVar1 + 1;
        if (iVar4 <= iVar1) break;
        piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(piVar6[4]);
        iVar1 = iVar2;
        if ((*piVar5 == 1) && (*piVar6 < 5)) {
          *piVar6 = 5;
        }
      }
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)piVar6[2],iVar1);
      if ((iVar1 != 0x15) && (*piVar6 < 3)) {
        *piVar6 = 3;
      }
      iVar4 = 0;
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[5]);
      if (0 < iVar1) {
        do {
          piVar5 = (int *)(*(code *)PTR_sk_value_006a7f24)(piVar6[5],iVar4);
          if (*(int *)piVar5[1] == 1) {
            if (*piVar5 < 3) {
              *piVar5 = 3;
            }
            if (*piVar6 < 3) {
              *piVar6 = 3;
            }
          }
          else {
            *piVar6 = 1;
          }
          iVar4 = iVar4 + 1;
          iVar1 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[5]);
        } while (iVar4 < iVar1);
      }
      if (*piVar6 < 1) {
        *piVar6 = 1;
      }
    }
    iVar7 = 0;
    iVar1 = 0;
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[1]);
    iVar4 = iVar1;
    if (0 < iVar2) {
      do {
        uVar3 = (*(code *)PTR_sk_value_006a7f24)(piVar6[1],iVar7);
        iVar1 = cms_DigestAlgorithm_init_bio(uVar3);
        if (iVar1 == 0) {
          if (iVar4 == 0) {
            return 0;
          }
          (*(code *)PTR_BIO_free_all_006a7f74)(iVar4,0);
          return 0;
        }
        if (iVar4 != 0) {
          (*(code *)PTR_BIO_push_006a85c0)(iVar4);
          iVar1 = iVar4;
        }
        iVar7 = iVar7 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(piVar6[1]);
        iVar4 = iVar1;
      } while (iVar7 < iVar2);
    }
    return iVar1;
  }
  return 0;
}

