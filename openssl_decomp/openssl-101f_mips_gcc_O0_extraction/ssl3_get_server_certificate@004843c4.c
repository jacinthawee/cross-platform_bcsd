
int ssl3_get_server_certificate(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int unaff_s3;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  int local_34;
  byte *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_34);
  if (local_34 == 0) goto LAB_00484510;
  iVar7 = *(int *)(param_1 + 0x58);
  iVar5 = *(int *)(iVar7 + 0x340);
  if ((iVar5 == 0xc) ||
     (((*(uint *)(*(int *)(iVar7 + 0x344) + 0x10) & 0x20) != 0 && (iVar5 == 0xe)))) {
    iVar3 = 1;
    *(undefined4 *)(iVar7 + 0x354) = 1;
    goto LAB_00484510;
  }
  if (iVar5 == 0xb) {
    pbVar11 = *(byte **)(param_1 + 0x40);
    iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar5 == 0) {
      unaff_s3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0x41,"s3_clnt.c",0x459);
      iVar7 = 0;
      iVar3 = -1;
      goto LAB_004844d8;
    }
    uVar13 = (uint)*pbVar11 << 0x10 | (uint)pbVar11[1] << 8 | (uint)pbVar11[2];
    if (iVar3 == uVar13 + 3) {
      pbVar14 = pbVar11 + 6;
      if (uVar13 == 0) {
LAB_004846c4:
        iVar3 = (*(code *)PTR_ssl_verify_cert_chain_006a9078)(param_1,iVar5);
        if ((*(int *)(param_1 + 200) == 0) || (0 < iVar3)) {
          (*(code *)PTR_ERR_clear_error_006a7fe0)();
          piVar4 = (int *)(*(code *)PTR_ssl_sess_cert_new_006a9060)();
          if (piVar4 == (int *)0x0) {
            unaff_s3 = 0;
            iVar7 = 0;
            iVar3 = -1;
            goto LAB_004844d8;
          }
          iVar3 = *(int *)(param_1 + 0xc0);
          if (*(int *)(iVar3 + 0x98) != 0) {
            (*(code *)PTR_ssl_sess_cert_free_006a905c)();
            iVar3 = *(int *)(param_1 + 0xc0);
          }
          puVar1 = PTR_sk_value_006a7f24;
          *(int **)(iVar3 + 0x98) = piVar4;
          *piVar4 = iVar5;
          iVar3 = (*(code *)puVar1)(iVar5,0);
          unaff_s3 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar3);
          iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
          if (((*(uint *)(iVar5 + 0xc) & 0x10) == 0) || ((*(uint *)(iVar5 + 0x10) & 0x20) == 0)) {
            if ((unaff_s3 == 0) ||
               (iVar5 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(unaff_s3), iVar5 != 0))
            {
              uVar8 = 0xef;
              uVar9 = 0x4b4;
              goto LAB_00484994;
            }
            iVar5 = ssl_cert_type(iVar3,unaff_s3);
            puVar1 = PTR_CRYPTO_add_lock_006a9080;
            if (iVar5 < 0) goto LAB_00484a18;
            piVar4[1] = iVar5;
            (*(code *)puVar1)(iVar3 + 0x10,1,3,"s3_clnt.c",0x4c5);
            if (piVar4[iVar5 * 3 + 3] != 0) {
              (*(code *)PTR_X509_free_006a7f90)();
            }
            iVar7 = *(int *)(*(int *)(param_1 + 0xc0) + 0x9c);
            piVar4[iVar5 * 3 + 3] = iVar3;
            piVar4[2] = (int)(piVar4 + iVar5 * 3 + 3);
            if (iVar7 != 0) {
              (*(code *)PTR_X509_free_006a7f90)();
            }
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar3 + 0x10,1,3,"s3_clnt.c",0x4cf);
            iVar6 = *(int *)(param_1 + 0xc0);
            *(int *)(iVar6 + 0x9c) = iVar3;
          }
          else {
            iVar3 = ssl_cert_type(iVar3,unaff_s3);
            iVar6 = *(int *)(param_1 + 0xc0);
            piVar4[1] = iVar3;
            piVar4[2] = 0;
            if (*(int *)(iVar6 + 0x9c) != 0) {
              (*(code *)PTR_X509_free_006a7f90)();
              iVar6 = *(int *)(param_1 + 0xc0);
            }
            *(undefined4 *)(iVar6 + 0x9c) = 0;
          }
          iVar5 = 0;
          iVar7 = 0;
          iVar3 = 1;
          *(undefined4 *)(iVar6 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
          goto LAB_004844d8;
        }
        unaff_s3 = 0;
        iVar7 = 0;
        uVar9 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0x86,"s3_clnt.c",0x48f);
        goto LAB_004844bc;
      }
      uVar10 = (uint)pbVar11[3] << 0x10 | (uint)pbVar11[4] << 8 | (uint)pbVar11[5];
      for (uVar12 = uVar10 + 3; uVar12 <= uVar13; uVar12 = uVar12 + uVar10 + 3) {
        local_30 = pbVar14;
        iVar7 = (*(code *)PTR_d2i_X509_006a9070)(0,&local_30,uVar10);
        if (iVar7 == 0) {
          unaff_s3 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0xd,"s3_clnt.c",0x473);
          uVar9 = 0x2a;
          goto LAB_004844bc;
        }
        if (local_30 != pbVar14 + uVar10) {
          unaff_s3 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0x87,"s3_clnt.c",0x479);
          uVar9 = 0x32;
          goto LAB_004844bc;
        }
        iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar5,iVar7);
        if (iVar3 == 0) {
          unaff_s3 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0x41,"s3_clnt.c",0x47e);
          iVar3 = -1;
          goto LAB_004844d8;
        }
        if (uVar13 <= uVar12) goto LAB_004846c4;
        uVar10 = (uint)*local_30 << 0x10 | (uint)local_30[1] << 8 | (uint)local_30[2];
        pbVar14 = local_30 + 3;
      }
      uVar8 = 0x87;
      uVar9 = 0x46a;
    }
    else {
      uVar8 = 0x9f;
      uVar9 = 0x461;
    }
    unaff_s3 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,uVar8,"s3_clnt.c",uVar9);
    iVar7 = 0;
    uVar9 = 0x32;
  }
  else {
    unaff_s3 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,0x72,"s3_clnt.c",0x452);
    iVar5 = 0;
    iVar7 = 0;
    uVar9 = 10;
  }
LAB_004844bc:
  while( true ) {
    ssl3_send_alert(param_1,2,uVar9);
    iVar3 = -1;
LAB_004844d8:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(unaff_s3);
    (*(code *)PTR_X509_free_006a7f90)(iVar7);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar5,PTR_X509_free_006a7f90);
LAB_00484510:
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00484a18:
    uVar8 = 0xf7;
    uVar9 = 0x4be;
LAB_00484994:
    iVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x90,uVar8,"s3_clnt.c",uVar9);
    iVar7 = 0;
    uVar9 = 2;
  }
  return iVar3;
}

