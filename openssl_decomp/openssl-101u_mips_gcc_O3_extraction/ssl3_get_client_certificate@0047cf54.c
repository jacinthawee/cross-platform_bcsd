
int ssl3_get_client_certificate(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  int local_34;
  byte *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x2180,0x2181,0xffffffff,param_1[0x42],&local_34)
  ;
  if (local_34 == 0) goto LAB_0047d04c;
  iVar5 = param_1[0x16];
  if (*(int *)(iVar5 + 0x340) == 0x10) {
    if ((param_1[0x32] & 3U) == 3) {
      iVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,199,"s3_srvr.c",0xc81);
      uVar3 = 0x28;
      goto LAB_0047d024;
    }
    if ((*param_1 < 0x301) || (*(int *)(iVar5 + 0x390) == 0)) {
      iVar2 = 1;
      *(undefined4 *)(iVar5 + 0x354) = 1;
      goto LAB_0047d04c;
    }
    uVar7 = 0xe9;
    uVar3 = 0xc8a;
LAB_0047d008:
    iVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,uVar7,"s3_srvr.c",uVar3);
    uVar3 = 10;
LAB_0047d024:
    ssl3_send_alert(param_1,2,uVar3);
  }
  else {
    if (*(int *)(iVar5 + 0x340) != 0xb) {
      uVar7 = 0x106;
      uVar3 = 0xc94;
      goto LAB_0047d008;
    }
    local_30 = (byte *)param_1[0x10];
    iVar5 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar5 != 0) {
      pbVar8 = local_30 + 3;
      uVar12 = (uint)*local_30 << 0x10 | (uint)local_30[1] << 8 | (uint)local_30[2];
      if (iVar2 == uVar12 + 3) {
        if (uVar12 != 0) {
          pbVar14 = local_30 + 6;
          if (uVar12 < 3) {
LAB_0047d3b0:
            local_30 = pbVar8;
            uVar9 = 0x87;
            uVar7 = 0xca8;
          }
          else {
            uVar10 = (uint)local_30[4] << 8 | (uint)local_30[3] << 0x10 | (uint)local_30[5];
            for (uVar13 = uVar10 + 3; local_30 = pbVar14, uVar13 <= uVar12;
                uVar13 = uVar13 + uVar10 + 3) {
              iVar2 = (*(code *)PTR_d2i_X509_006a7fe0)(0,&local_30,uVar10);
              if (iVar2 == 0) {
                uVar7 = 0xd;
                uVar3 = 0xcb6;
                goto LAB_0047d2a8;
              }
              if (local_30 != pbVar14 + uVar10) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,0x87,"s3_srvr.c",0xcbc);
                ssl3_send_alert(param_1,2,0x32);
                param_1[0xd] = 5;
LAB_0047d0d0:
                (*(code *)PTR_X509_free_006a6e90)(iVar2);
                goto LAB_0047d0e0;
              }
              iVar6 = (*(code *)PTR_sk_push_006a6fa8)(iVar5,iVar2);
              if (iVar6 == 0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,0x41,"s3_srvr.c",0xcc0);
                param_1[0xd] = 5;
                goto LAB_0047d0d0;
              }
              pbVar8 = local_30;
              if (uVar12 <= uVar13) goto LAB_0047d304;
              if (uVar12 < uVar13 + 3) goto LAB_0047d3b0;
              pbVar14 = local_30 + 3;
              uVar10 = (uint)*local_30 << 0x10 | (uint)local_30[1] << 8 | (uint)local_30[2];
            }
            uVar9 = 0x87;
            uVar7 = 0xcaf;
          }
          goto LAB_0047d19c;
        }
LAB_0047d304:
        local_30 = pbVar8;
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar5);
        if (iVar2 < 1) {
          if (*param_1 == 0x300) {
            uVar9 = 0xb0;
            uVar7 = 0xccc;
          }
          else {
            if ((param_1[0x32] & 3U) != 3) {
              if ((*(int *)(param_1[0x16] + 0x178) == 0) ||
                 (iVar2 = ssl3_digest_cached_records(param_1), iVar2 != 0)) goto LAB_0047d330;
              uVar3 = 0x50;
              goto LAB_0047d024;
            }
            uVar9 = 199;
            uVar7 = 0xcd3;
          }
          uVar3 = 0x28;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,uVar9,"s3_srvr.c",uVar7);
        }
        else {
          iVar2 = (*(code *)PTR_ssl_verify_cert_chain_006a7fe4)(param_1,iVar5);
          if (0 < iVar2) {
LAB_0047d330:
            iVar2 = param_1[0x30];
            if (*(int *)(iVar2 + 0x9c) != 0) {
              (*(code *)PTR_X509_free_006a6e90)();
              iVar2 = param_1[0x30];
            }
            uVar3 = (*(code *)PTR_sk_shift_006a724c)(iVar5);
            iVar11 = param_1[0x30];
            iVar6 = param_1[0x3b];
            *(undefined4 *)(iVar2 + 0x9c) = uVar3;
            *(int *)(iVar11 + 0xa0) = iVar6;
            if (*(int *)(iVar11 + 0x98) == 0) {
              uVar3 = (*(code *)PTR_ssl_sess_cert_new_006a7fec)();
              *(undefined4 *)(iVar11 + 0x98) = uVar3;
              piVar4 = *(int **)(param_1[0x30] + 0x98);
              if (piVar4 == (int *)0x0) {
                uVar7 = 0x41;
                uVar3 = 0xcf2;
                goto LAB_0047d2a8;
              }
            }
            else {
              piVar4 = *(int **)(iVar11 + 0x98);
            }
            if (*piVar4 != 0) {
              (*(code *)PTR_sk_pop_free_006a7058)(*piVar4,PTR_X509_free_006a6e90);
              piVar4 = *(int **)(param_1[0x30] + 0x98);
            }
            *piVar4 = iVar5;
            iVar2 = 1;
            goto LAB_0047d04c;
          }
          uVar3 = ssl_verify_alarm_type(param_1[0x3b]);
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,0xb2,"s3_srvr.c",0xce1);
        }
      }
      else {
        uVar9 = 0x9f;
        uVar7 = 0xca1;
        local_30 = pbVar8;
LAB_0047d19c:
        uVar3 = 0x32;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,uVar9,"s3_srvr.c",uVar7);
      }
      goto LAB_0047d024;
    }
    uVar7 = 0x41;
    uVar3 = 0xc9a;
LAB_0047d2a8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x89,uVar7,"s3_srvr.c",uVar3);
  }
  param_1[0xd] = 5;
  if (iVar5 == 0) {
    iVar2 = -1;
  }
  else {
LAB_0047d0e0:
    (*(code *)PTR_sk_pop_free_006a7058)(iVar5,PTR_X509_free_006a6e90);
    iVar2 = -1;
  }
LAB_0047d04c:
  if (local_2c == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar2 + 0x34) != 0x2140) {
    iVar2 = ssl3_do_write(iVar2,0x16);
    return iVar2;
  }
  iVar5 = (*(code *)PTR_ssl_get_server_send_cert_006a7ff0)();
  if ((iVar5 == 0) &&
     ((iVar6 = *(int *)(*(int *)(iVar2 + 0x58) + 0x344), *(int *)(iVar6 + 0x10) != 0x20 ||
      ((*(uint *)(iVar6 + 0xc) & 0x10) != 0)))) {
    uVar3 = 0xd1b;
  }
  else {
    iVar5 = ssl3_output_cert_chain(iVar2,iVar5);
    if (iVar5 != 0) {
      *(int *)(iVar2 + 0x44) = iVar5;
      *(undefined4 *)(iVar2 + 0x48) = 0;
      *(undefined4 *)(iVar2 + 0x34) = 0x2141;
      iVar2 = ssl3_do_write(iVar2,0x16);
      return iVar2;
    }
    uVar3 = 0xd23;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9a,0x44,"s3_srvr.c",uVar3);
  *(undefined4 *)(iVar2 + 0x34) = 5;
  return 0;
}

