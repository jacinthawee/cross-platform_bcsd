
undefined4
ssl_parse_clienthello_use_srtp_ext(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  if (param_3 < 3) {
    uVar11 = 0x161;
    uVar10 = 0x13f;
  }
  else {
    uVar12 = (uint)*param_2;
    param_3 = param_3 + -2;
    if ((*param_2 & 1) == 0) {
      if ((int)uVar12 < param_3) {
        param_2 = param_2 + 1;
        iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
        if (uVar12 != 0) {
          do {
            while( true ) {
              uVar12 = uVar12 - 2;
              uVar3 = *param_2;
              param_3 = param_3 + -2;
              param_2 = param_2 + 1;
              piVar4 = (int *)srtp_known_profiles;
              uVar5 = srtp_known_profiles._4_4_;
              if (srtp_known_profiles._0_4_ == 0) break;
              while (uVar3 != uVar5) {
                if (piVar4[2] == 0) goto LAB_004a8d24;
                puVar1 = (uint *)(piVar4 + 3);
                piVar4 = piVar4 + 2;
                uVar5 = *puVar1;
              }
              (*(code *)PTR_sk_push_006a80a8)(iVar6);
              if (uVar12 == 0) {
                bVar2 = *(byte *)param_2;
                goto LAB_004a8d30;
              }
            }
LAB_004a8d24:
          } while (uVar12 != 0);
        }
        bVar2 = *(byte *)param_2;
LAB_004a8d30:
        if ((uint)bVar2 == param_3 - 1U) {
          iVar14 = 0;
          if ((param_1 == 0) || (iVar14 = *(int *)(param_1 + 0x17c), iVar14 != 0)) {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            if (*(int *)(param_1 + 0xe4) != 0) {
              iVar14 = *(int *)(*(int *)(param_1 + 0xe4) + 0x1b4);
            }
          }
          do {
            iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar14);
            if (iVar7 <= iVar13) {
LAB_004a8e68:
              if (iVar6 == 0) {
                return 0;
              }
              (*(code *)PTR_sk_free_006a7f80)(iVar6);
              return 0;
            }
            iVar8 = (*(code *)PTR_sk_value_006a7f24)(iVar14,iVar13);
            iVar7 = 0;
            while( true ) {
              iVar9 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
              if (iVar9 <= iVar7) break;
              iVar9 = (*(code *)PTR_sk_value_006a7f24)(iVar6,iVar7);
              iVar7 = iVar7 + 1;
              if (*(int *)(iVar9 + 4) == *(int *)(iVar8 + 4)) {
                *(int *)(param_1 + 0x180) = iVar8;
                *param_4 = 0;
                goto LAB_004a8e68;
              }
            }
            iVar13 = iVar13 + 1;
          } while( true );
        }
        uVar11 = 0x160;
        uVar10 = 0x171;
      }
      else {
        uVar11 = 0x161;
        uVar10 = 0x153;
      }
    }
    else {
      uVar11 = 0x161;
      uVar10 = 0x14b;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x136,uVar11,"d1_srtp.c",uVar10);
  *param_4 = 0x32;
  return 1;
}

