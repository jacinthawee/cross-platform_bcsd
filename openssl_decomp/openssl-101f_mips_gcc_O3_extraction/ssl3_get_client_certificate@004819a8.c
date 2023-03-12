
int ssl3_get_client_certificate(int *param_1)

{
  undefined *puVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  int local_34;
  byte *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_34)
  ;
  if (local_34 == 0) goto LAB_00481a98;
  iVar6 = param_1[0x16];
  if (*(int *)(iVar6 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      iVar6 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,199,"s3_srvr.c",0xc71);
      uVar4 = 0x28;
      goto LAB_00481a78;
    }
    if ((*param_1 < 0x301) || (*(int *)(iVar6 + 0x390) == 0)) {
      iVar3 = 1;
      *(undefined4 *)(iVar6 + 0x354) = 1;
      goto LAB_00481a98;
    }
    uVar8 = 0xe9;
    uVar4 = 0xc78;
LAB_00481a5c:
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,uVar8,"s3_srvr.c",uVar4);
    uVar4 = 10;
LAB_00481a78:
    ssl3_send_alert(param_1,2,uVar4);
    if (iVar6 == 0) {
      iVar3 = -1;
      goto LAB_00481a98;
    }
  }
  else {
    if (*(int *)(iVar6 + 0x340) != 0xb) {
      uVar8 = 0x106;
      uVar4 = 0xc83;
      goto LAB_00481a5c;
    }
    local_30 = (byte *)param_1[0x10];
    iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (iVar6 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,0x41,"s3_srvr.c",0xc8a);
      iVar3 = -1;
      goto LAB_00481a98;
    }
    uVar13 = (uint)*local_30 << 0x10 | (uint)local_30[1] << 8 | (uint)local_30[2];
    if (iVar3 != uVar13 + 3) {
      uVar9 = 0x9f;
      uVar8 = 0xc92;
      local_30 = local_30 + 3;
LAB_00481be0:
      uVar4 = 0x32;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,uVar9,"s3_srvr.c",uVar8);
      goto LAB_00481a78;
    }
    pbVar14 = local_30 + 6;
    pbVar2 = local_30 + 3;
    if (uVar13 != 0) {
      uVar10 = (uint)local_30[4] << 8 | (uint)local_30[3] << 0x10 | (uint)local_30[5];
      for (uVar12 = uVar10 + 3; local_30 = pbVar14, uVar12 <= uVar13; uVar12 = uVar12 + uVar10 + 3)
      {
        iVar3 = (*(code *)PTR_d2i_X509_006a9070)(0,&local_30,uVar10);
        if (iVar3 == 0) {
          uVar8 = 0xd;
          uVar4 = 0xca3;
          goto LAB_00481cd4;
        }
        if (local_30 != pbVar14 + uVar10) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,0x87,"s3_srvr.c",0xca9);
          ssl3_send_alert(param_1,2,0x32);
LAB_00481b14:
          (*(code *)PTR_X509_free_006a7f90)(iVar3);
          goto LAB_00481b24;
        }
        iVar7 = (*(code *)PTR_sk_push_006a80a8)(iVar6,iVar3);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,0x41,"s3_srvr.c",0xcae);
          goto LAB_00481b14;
        }
        pbVar2 = local_30;
        if (uVar13 <= uVar12) goto LAB_00481d30;
        pbVar14 = local_30 + 3;
        uVar10 = (uint)*local_30 << 0x10 | (uint)local_30[1] << 8 | (uint)local_30[2];
      }
      uVar9 = 0x87;
      uVar8 = 0xc9b;
      goto LAB_00481be0;
    }
LAB_00481d30:
    local_30 = pbVar2;
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(iVar6);
    if (iVar3 < 1) {
      if (*param_1 == 0x300) {
        uVar9 = 0xb0;
        uVar8 = 0xcbb;
      }
      else {
        if ((param_1[0x32] & 3U) != 3) {
          if ((*(int *)(param_1[0x16] + 0x178) != 0) &&
             (iVar3 = ssl3_digest_cached_records(param_1), iVar3 == 0)) {
            uVar4 = 0x50;
            goto LAB_00481a78;
          }
          goto LAB_00481d5c;
        }
        uVar9 = 199;
        uVar8 = 0xcc2;
      }
      uVar4 = 0x28;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,uVar9,"s3_srvr.c",uVar8);
      goto LAB_00481a78;
    }
    iVar3 = (*(code *)PTR_ssl_verify_cert_chain_006a9078)(param_1,iVar6);
    if (iVar3 < 1) {
      uVar4 = ssl_verify_alarm_type(param_1[0x3b]);
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,0xb2,"s3_srvr.c",0xcd3);
      goto LAB_00481a78;
    }
LAB_00481d5c:
    iVar3 = param_1[0x30];
    if (*(int *)(iVar3 + 0x9c) != 0) {
      (*(code *)PTR_X509_free_006a7f90)();
      iVar3 = param_1[0x30];
    }
    uVar4 = (*(code *)PTR_sk_shift_006a8360)(iVar6);
    iVar11 = param_1[0x30];
    iVar7 = param_1[0x3b];
    *(undefined4 *)(iVar3 + 0x9c) = uVar4;
    *(int *)(iVar11 + 0xa0) = iVar7;
    if (*(int *)(iVar11 + 0x98) != 0) {
      piVar5 = *(int **)(iVar11 + 0x98);
LAB_00481da8:
      if (*piVar5 != 0) {
        (*(code *)PTR_sk_pop_free_006a8158)(*piVar5,PTR_X509_free_006a7f90);
        piVar5 = *(int **)(param_1[0x30] + 0x98);
      }
      *piVar5 = iVar6;
      iVar3 = 1;
      goto LAB_00481a98;
    }
    uVar4 = (*(code *)PTR_ssl_sess_cert_new_006a9060)();
    *(undefined4 *)(iVar11 + 0x98) = uVar4;
    piVar5 = *(int **)(param_1[0x30] + 0x98);
    if (piVar5 != (int *)0x0) goto LAB_00481da8;
    uVar8 = 0x41;
    uVar4 = 0xce4;
LAB_00481cd4:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x89,uVar8,"s3_srvr.c",uVar4);
  }
LAB_00481b24:
  (*(code *)PTR_sk_pop_free_006a8158)(iVar6,PTR_X509_free_006a7f90);
  iVar3 = -1;
LAB_00481a98:
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar3 + 0x34) != 0x2140) {
    iVar3 = ssl3_do_write(iVar3,0x16);
    return iVar3;
  }
  iVar6 = (*(code *)PTR_ssl_get_server_send_cert_006a915c)();
  if ((iVar6 == 0) &&
     ((iVar7 = *(int *)(*(int *)(iVar3 + 0x58) + 0x344), *(int *)(iVar7 + 0x10) != 0x20 ||
      ((*(uint *)(iVar7 + 0xc) & 0x10) != 0)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9a,0x44,"s3_srvr.c",0xd0a);
    return 0;
  }
  uVar4 = ssl3_output_cert_chain(iVar3,iVar6);
  *(undefined4 *)(iVar3 + 0x44) = uVar4;
  *(undefined4 *)(iVar3 + 0x48) = 0;
  *(undefined4 *)(iVar3 + 0x34) = 0x2141;
  iVar3 = ssl3_do_write(iVar3,0x16);
  return iVar3;
}

