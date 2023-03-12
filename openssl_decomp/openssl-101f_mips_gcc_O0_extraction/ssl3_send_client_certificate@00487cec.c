
undefined4 ssl3_send_client_certificate(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int local_1c;
  int local_18;
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar3 = param_1[0xd];
  local_1c = 0;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iVar3 == 0x1170) {
    if ((((int **)param_1[0x26] == (int **)0x0) || (piVar5 = *(int **)param_1[0x26], *piVar5 == 0))
       || (piVar5[1] == 0)) {
      param_1[0xd] = 0x1171;
      goto LAB_00487df4;
    }
LAB_00487da4:
    iVar3 = param_1[0x16];
LAB_00487da8:
    iVar3 = *(int *)(iVar3 + 0x358);
    param_1[0xd] = 0x1173;
    if (iVar3 == 2) {
      uVar4 = 0;
    }
    else {
      uVar4 = **(undefined4 **)param_1[0x26];
    }
    iVar3 = ssl3_output_cert_chain(param_1,uVar4);
    param_1[0x11] = iVar3;
    param_1[0x12] = 0;
  }
  else {
    if (iVar3 == 0x1171) {
LAB_00487df4:
      iVar3 = param_1[0x39];
      iVar6 = *(int *)(iVar3 + 0xfc);
      if (iVar6 == 0) {
LAB_00487e4c:
        if (*(code **)(iVar3 + 0x74) != (code *)0x0) {
          uVar9 = (**(code **)(iVar3 + 0x74))(param_1,&local_1c,&local_18);
          goto LAB_00487e6c;
        }
        uVar9 = 0;
        param_1[6] = 1;
      }
      else {
        uVar4 = (*(code *)PTR_SSL_get_client_CA_list_006a8a68)(param_1);
        uVar9 = (*(code *)PTR_ENGINE_load_ssl_client_cert_006a91d0)
                          (iVar6,param_1,uVar4,&local_1c,&local_18,0,0,0);
        if (uVar9 == 0) {
          iVar3 = param_1[0x39];
          goto LAB_00487e4c;
        }
LAB_00487e6c:
        if ((int)uVar9 < 0) {
          uVar4 = 0xffffffff;
          param_1[6] = 4;
          goto LAB_00487d58;
        }
        param_1[6] = 1;
        puVar1 = PTR_SSL_use_certificate_006a9098;
        if (uVar9 == 1) {
          if ((local_18 == 0) || (local_1c == 0)) {
            uVar9 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x97,0x6a,"s3_clnt.c",0xc35);
          }
          else {
            param_1[0xd] = 0x1171;
            iVar3 = (*(code *)puVar1)(param_1);
            if (iVar3 == 0) {
              uVar9 = 0;
            }
            else {
              iVar3 = (*(code *)PTR_SSL_use_PrivateKey_006a909c)(param_1,local_18);
              uVar9 = (uint)(iVar3 != 0);
            }
          }
        }
      }
      if (local_1c != 0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
      if (local_18 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (uVar9 != 0) goto LAB_00487da4;
      if (*param_1 == 0x300) {
        *(undefined4 *)(param_1[0x16] + 0x358) = 0;
        ssl3_send_alert(param_1,1,0x29);
        uVar4 = 1;
        goto LAB_00487d58;
      }
      iVar3 = param_1[0x16];
      *(undefined4 *)(iVar3 + 0x358) = 2;
      goto LAB_00487da8;
    }
    if (iVar3 == 0x1172) goto LAB_00487da4;
  }
  uVar4 = ssl3_do_write(param_1,0x16);
LAB_00487d58:
  if (local_14 == *(int *)puVar2) {
    return uVar4;
  }
  iVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar6 = *(int *)(*(int *)(iVar3 + 0x58) + 0x344);
  uVar9 = *(uint *)(iVar6 + 0x10);
  if ((uVar9 & 0x2c) != 0) {
    return 1;
  }
  uVar12 = *(uint *)(iVar6 + 0xc);
  if ((uVar12 & 0x100) != 0) {
    return 1;
  }
  iVar6 = *(int *)(*(int *)(iVar3 + 0xc0) + 0x98);
  if (iVar6 != 0) {
    if (*(int *)(iVar6 + 4) == 5) {
      iVar6 = (*(code *)PTR_ssl_check_srvr_ecc_cert_and_alg_006a91d4)
                        (*(undefined4 *)(iVar6 + 0x48),iVar3);
      if (iVar6 != 0) {
        return 1;
      }
      uVar8 = 0x130;
      uVar4 = 0xc85;
    }
    else {
      iVar10 = *(int *)(iVar6 + 0x6c);
      iVar11 = *(int *)(iVar6 + 0x70);
      iVar6 = iVar6 + *(int *)(iVar6 + 4) * 0xc;
      uVar4 = (*(code *)PTR_X509_get_pubkey_006a8008)(*(undefined4 *)(iVar6 + 0xc));
      uVar7 = (*(code *)PTR_X509_certificate_type_006a914c)(*(undefined4 *)(iVar6 + 0xc),uVar4);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar4);
      if (((uVar9 & 1) == 0) || ((uVar7 & 0x11) == 0x11)) {
        if (((uVar9 & 2) == 0) || ((uVar7 & 0x12) == 0x12)) {
          if ((((uVar12 & 1) == 0) || ((uVar7 & 0x21) == 0x21)) || (iVar10 != 0)) {
            if ((((uVar12 & 8) == 0) || ((uVar7 & 0x44) == 0x44)) || (iVar11 != 0)) {
              if (((uVar12 & 2) == 0) || ((uVar7 & 0x104) == 0x104)) {
                if (((uVar12 & 4) == 0) || ((uVar7 & 0x204) == 0x204)) {
                  if ((*(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20) & 2) == 0) {
                    return 1;
                  }
                  if ((uVar7 & 0x1000) != 0) {
                    return 1;
                  }
                  if ((uVar12 & 1) == 0) {
                    if ((uVar12 & 0xe) == 0) {
                      uVar8 = 0xfa;
                      uVar4 = 0xcd8;
                    }
                    else {
                      if (iVar11 != 0) {
                        iVar6 = (*(code *)PTR_DH_size_006a91d8)(iVar11);
                        iVar10 = 0x400;
                        if ((*(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20) & 8) != 0) {
                          iVar10 = 0x200;
                        }
                        if (iVar6 << 3 <= iVar10) {
                          return 1;
                        }
                      }
                      uVar8 = 0xa6;
                      uVar4 = 0xcd1;
                    }
                  }
                  else {
                    if (iVar10 != 0) {
                      iVar6 = (*(code *)PTR_RSA_size_006a8730)(iVar10);
                      iVar10 = 0x400;
                      if ((*(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20) & 8) != 0) {
                        iVar10 = 0x200;
                      }
                      if (iVar6 << 3 <= iVar10) {
                        return 1;
                      }
                    }
                    uVar8 = 0xa7;
                    uVar4 = 0xcc5;
                  }
                }
                else {
                  uVar8 = 0xa2;
                  uVar4 = 0xcb7;
                }
              }
              else {
                uVar8 = 0xa4;
                uVar4 = 0xcb1;
              }
            }
            else {
              uVar8 = 0xa3;
              uVar4 = 0xcac;
            }
          }
          else {
            uVar8 = 0xa9;
            uVar4 = 0xca4;
          }
        }
        else {
          uVar8 = 0xa5;
          uVar4 = 0xc9c;
        }
      }
      else {
        uVar8 = 0xaa;
        uVar4 = 0xc96;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x82,uVar8,"s3_clnt.c",uVar4);
    ssl3_send_alert(iVar3,2,0x28);
    return 0;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x82,0x44,"s3_clnt.c",0xc71);
  return 0;
}

