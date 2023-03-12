
undefined4 ssl3_send_client_certificate(int *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int local_1c;
  int local_18;
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iVar3 = param_1[0xd];
  local_1c = 0;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iVar3 == 0x1170) {
    if ((((int **)param_1[0x26] == (int **)0x0) || (piVar5 = *(int **)param_1[0x26], *piVar5 == 0))
       || (piVar5[1] == 0)) {
      param_1[0xd] = 0x1171;
      goto LAB_00483b48;
    }
LAB_00483afc:
    iVar3 = param_1[0x16];
LAB_00483b00:
    iVar3 = *(int *)(iVar3 + 0x358);
    param_1[0xd] = 0x1173;
    if (iVar3 == 2) {
      iVar3 = ssl3_output_cert_chain(param_1,0);
    }
    else {
      iVar3 = ssl3_output_cert_chain(param_1,**(undefined4 **)param_1[0x26]);
    }
    if (iVar3 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x97,0x44,"s3_clnt.c",0xcd8);
      ssl3_send_alert(param_1,2,0x50);
      uVar4 = 0;
      param_1[0xd] = 5;
    }
    else {
      param_1[0x11] = iVar3;
      param_1[0x12] = 0;
LAB_00483a9c:
      uVar4 = ssl3_do_write(param_1,0x16);
    }
  }
  else {
    if (iVar3 != 0x1171) {
      if (iVar3 == 0x1172) goto LAB_00483afc;
      goto LAB_00483a9c;
    }
LAB_00483b48:
    iVar3 = param_1[0x39];
    iVar6 = *(int *)(iVar3 + 0xfc);
    if (iVar6 == 0) {
LAB_00483ba0:
      if (*(code **)(iVar3 + 0x74) != (code *)0x0) {
        uVar10 = (**(code **)(iVar3 + 0x74))(param_1,&local_1c,&local_18);
        goto LAB_00483bc0;
      }
      uVar10 = 0;
      param_1[6] = 1;
LAB_00483bd4:
      if (local_1c != 0) {
        (*(code *)PTR_X509_free_006a6e90)();
      }
      if (local_18 != 0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      if (uVar10 != 0) goto LAB_00483afc;
      if (*param_1 != 0x300) {
        iVar3 = param_1[0x16];
        *(undefined4 *)(iVar3 + 0x358) = 2;
        goto LAB_00483b00;
      }
      *(undefined4 *)(param_1[0x16] + 0x358) = 0;
      ssl3_send_alert(param_1,1,0x29);
      uVar4 = 1;
    }
    else {
      uVar4 = (*(code *)PTR_SSL_get_client_CA_list_006a797c)(param_1);
      uVar10 = (*(code *)PTR_ENGINE_load_ssl_client_cert_006a8090)
                         (iVar6,param_1,uVar4,&local_1c,&local_18,0,0,0);
      if (uVar10 == 0) {
        iVar3 = param_1[0x39];
        goto LAB_00483ba0;
      }
LAB_00483bc0:
      if (-1 < (int)uVar10) {
        param_1[6] = 1;
        puVar1 = PTR_SSL_use_certificate_006a8094;
        if (uVar10 == 1) {
          if ((local_18 == 0) || (local_1c == 0)) {
            uVar10 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x97,0x6a,"s3_clnt.c",0xcbd);
          }
          else {
            param_1[0xd] = 0x1171;
            iVar3 = (*(code *)puVar1)(param_1);
            if (iVar3 == 0) {
              uVar10 = 0;
            }
            else {
              iVar3 = (*(code *)PTR_SSL_use_PrivateKey_006a8098)(param_1,local_18);
              uVar10 = (uint)(iVar3 != 0);
            }
          }
        }
        goto LAB_00483bd4;
      }
      uVar4 = 0xffffffff;
      param_1[6] = 4;
    }
  }
  if (local_14 == *(int *)puVar2) {
    return uVar4;
  }
  iVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = *(int *)(*(int *)(iVar3 + 0x58) + 0x344);
  uVar10 = *(uint *)(iVar6 + 0x10);
  if ((uVar10 & 0x2c) != 0) {
    return 1;
  }
  uVar13 = *(uint *)(iVar6 + 0xc);
  if ((uVar13 & 0x100) != 0) {
    return 1;
  }
  iVar6 = *(int *)(*(int *)(iVar3 + 0xc0) + 0x98);
  if (iVar6 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0x44,"s3_clnt.c",0xcfe);
    return 0;
  }
  if (*(int *)(iVar6 + 4) == 5) {
    iVar6 = (*(code *)PTR_ssl_check_srvr_ecc_cert_and_alg_006a809c)
                      (*(undefined4 *)(iVar6 + 0x48),iVar3);
    if (iVar6 != 0) {
      return 1;
    }
    uVar9 = 0x130;
    uVar4 = 0xd0f;
  }
  else {
    iVar12 = *(int *)(iVar6 + 0x6c);
    iVar11 = *(int *)(iVar6 + 0x70);
    iVar6 = iVar6 + *(int *)(iVar6 + 4) * 0xc;
    uVar4 = (*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar6 + 0xc));
    iVar7 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(uVar4);
    uVar8 = (*(code *)PTR_X509_certificate_type_006a7fd0)(*(undefined4 *)(iVar6 + 0xc),uVar4);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar4);
    if (((uVar10 & 1) == 0) || ((uVar8 & 0x11) == 0x11)) {
      if (((uVar10 & 2) == 0) || ((uVar8 & 0x12) == 0x12)) {
        if ((uVar13 & 1) == 0) {
LAB_00483fa0:
          uVar10 = uVar13 & 8;
          if ((uVar10 == 0) || (iVar11 != 0)) {
            if (((uVar13 & 2) == 0) || ((uVar8 & 0x104) == 0x104)) {
              if (((uVar13 & 4) == 0) || ((uVar8 & 0x204) == 0x204)) {
                if (uVar10 == 0) {
                  uVar8 = *(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20);
                  if ((uVar8 & 2) == 0) {
                    return 1;
                  }
LAB_0048402c:
                  iVar14 = 0x200;
                  iVar6 = 0x200;
                  if ((uVar8 & 8) == 0) {
                    iVar6 = 0x400;
                  }
                  if (iVar7 <= iVar6) {
                    return 1;
                  }
                  if ((uVar13 & 1) == 0) {
                    if (uVar10 == 0) {
                      if ((uVar13 & 6) == 0) {
                        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0xfa,"s3_clnt.c",0xd84);
                        uVar4 = 0x28;
                        goto LAB_00483e80;
                      }
                      uVar9 = 0xa6;
                      uVar4 = 0xd7e;
                    }
                    else {
                      iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar11 + 8));
                      if ((*(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20) & 8) == 0) {
                        iVar14 = 0x400;
                      }
                      if (iVar6 <= iVar14) {
                        return 1;
                      }
                      uVar9 = 0xa6;
                      uVar4 = 0xd77;
                    }
                  }
                  else {
                    if (iVar12 == 0) {
                      uVar9 = 0xa7;
                      uVar4 = 0xd64;
                      goto LAB_00483e68;
                    }
                    iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar12 + 0x10));
                    if ((*(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20) & 8) == 0) {
                      iVar14 = 0x400;
                    }
                    if (iVar6 <= iVar14) {
                      return 1;
                    }
                    uVar9 = 0xa7;
                    uVar4 = 0xd6b;
                  }
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,uVar9,"s3_clnt.c",uVar4);
                  uVar4 = 0x3c;
                  goto LAB_00483e80;
                }
                iVar6 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar11 + 8));
                uVar8 = *(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20);
                if ((uVar8 & 2) == 0) {
                  if (0x3ff < iVar6) {
                    return 1;
                  }
                }
                else if (0x1ff < iVar6) goto LAB_0048402c;
                uVar9 = 0x174;
                uVar4 = 0xd58;
              }
              else {
                uVar9 = 0xa2;
                uVar4 = 0xd4e;
              }
            }
            else {
              uVar9 = 0xa4;
              uVar4 = 0xd48;
            }
            goto LAB_00483e68;
          }
          uVar4 = 0xd43;
        }
        else {
          uVar10 = *(uint *)(*(int *)(*(int *)(iVar3 + 0x58) + 0x344) + 0x20);
          if ((uVar10 & 2) == 0) {
            if ((uVar8 & 0x21) != 0x21) {
              uVar9 = 0xa9;
              uVar4 = 0xd2d;
              goto LAB_00483e68;
            }
            goto LAB_00483fa0;
          }
          iVar6 = 0x200;
          if ((uVar10 & 8) == 0) {
            iVar6 = 0x400;
          }
          if (iVar6 < iVar7) goto LAB_00483fa0;
          if ((uVar8 & 0x21) != 0x21) {
            uVar9 = 0xa9;
            uVar4 = 0xd33;
            goto LAB_00483e68;
          }
          if (iVar12 == 0) goto LAB_00483fa0;
          uVar4 = 0xd39;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0x44,"s3_clnt.c",uVar4);
        uVar4 = 0x50;
        goto LAB_00483e80;
      }
      uVar9 = 0xa5;
      uVar4 = 0xd24;
    }
    else {
      uVar9 = 0xaa;
      uVar4 = 0xd1e;
    }
  }
LAB_00483e68:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,uVar9,"s3_clnt.c",uVar4);
  uVar4 = 0x28;
LAB_00483e80:
  ssl3_send_alert(iVar3,2,uVar4);
  return 0;
}

