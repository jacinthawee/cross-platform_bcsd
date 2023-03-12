
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar6 = *(uint *)(iVar1 + 0x10);
  if ((uVar6 & 0x2c) != 0) {
    return 1;
  }
  uVar9 = *(uint *)(iVar1 + 0xc);
  if ((uVar9 & 0x100) != 0) {
    return 1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0x44,"s3_clnt.c",0xcfe);
    return 0;
  }
  if (*(int *)(iVar1 + 4) == 5) {
    iVar1 = (*(code *)PTR_ssl_check_srvr_ecc_cert_and_alg_006a809c)
                      (*(undefined4 *)(iVar1 + 0x48),param_1);
    if (iVar1 != 0) {
      return 1;
    }
    uVar5 = 0x130;
    uVar2 = 0xd0f;
  }
  else {
    iVar8 = *(int *)(iVar1 + 0x6c);
    iVar7 = *(int *)(iVar1 + 0x70);
    iVar1 = iVar1 + *(int *)(iVar1 + 4) * 0xc;
    uVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)(*(undefined4 *)(iVar1 + 0xc));
    iVar3 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(uVar2);
    uVar4 = (*(code *)PTR_X509_certificate_type_006a7fd0)(*(undefined4 *)(iVar1 + 0xc),uVar2);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar2);
    if (((uVar6 & 1) == 0) || ((uVar4 & 0x11) == 0x11)) {
      if (((uVar6 & 2) == 0) || ((uVar4 & 0x12) == 0x12)) {
        if ((uVar9 & 1) == 0) {
LAB_00483fa0:
          uVar6 = uVar9 & 8;
          if ((uVar6 == 0) || (iVar7 != 0)) {
            if (((uVar9 & 2) == 0) || ((uVar4 & 0x104) == 0x104)) {
              if (((uVar9 & 4) == 0) || ((uVar4 & 0x204) == 0x204)) {
                if (uVar6 == 0) {
                  uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
                  if ((uVar4 & 2) == 0) {
                    return 1;
                  }
LAB_0048402c:
                  iVar10 = 0x200;
                  iVar1 = 0x200;
                  if ((uVar4 & 8) == 0) {
                    iVar1 = 0x400;
                  }
                  if (iVar3 <= iVar1) {
                    return 1;
                  }
                  if ((uVar9 & 1) == 0) {
                    if (uVar6 == 0) {
                      if ((uVar9 & 6) == 0) {
                        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0xfa,"s3_clnt.c",0xd84);
                        uVar2 = 0x28;
                        goto LAB_00483e80;
                      }
                      uVar5 = 0xa6;
                      uVar2 = 0xd7e;
                    }
                    else {
                      iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar7 + 8));
                      if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
                        iVar10 = 0x400;
                      }
                      if (iVar1 <= iVar10) {
                        return 1;
                      }
                      uVar5 = 0xa6;
                      uVar2 = 0xd77;
                    }
                  }
                  else {
                    if (iVar8 == 0) {
                      uVar5 = 0xa7;
                      uVar2 = 0xd64;
                      goto LAB_00483e68;
                    }
                    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar8 + 0x10));
                    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
                      iVar10 = 0x400;
                    }
                    if (iVar1 <= iVar10) {
                      return 1;
                    }
                    uVar5 = 0xa7;
                    uVar2 = 0xd6b;
                  }
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,uVar5,"s3_clnt.c",uVar2);
                  uVar2 = 0x3c;
                  goto LAB_00483e80;
                }
                iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar7 + 8));
                uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
                if ((uVar4 & 2) == 0) {
                  if (0x3ff < iVar1) {
                    return 1;
                  }
                }
                else if (0x1ff < iVar1) goto LAB_0048402c;
                uVar5 = 0x174;
                uVar2 = 0xd58;
              }
              else {
                uVar5 = 0xa2;
                uVar2 = 0xd4e;
              }
            }
            else {
              uVar5 = 0xa4;
              uVar2 = 0xd48;
            }
            goto LAB_00483e68;
          }
          uVar2 = 0xd43;
        }
        else {
          uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
          if ((uVar6 & 2) == 0) {
            if ((uVar4 & 0x21) != 0x21) {
              uVar5 = 0xa9;
              uVar2 = 0xd2d;
              goto LAB_00483e68;
            }
            goto LAB_00483fa0;
          }
          iVar1 = 0x200;
          if ((uVar6 & 8) == 0) {
            iVar1 = 0x400;
          }
          if (iVar1 < iVar3) goto LAB_00483fa0;
          if ((uVar4 & 0x21) != 0x21) {
            uVar5 = 0xa9;
            uVar2 = 0xd33;
            goto LAB_00483e68;
          }
          if (iVar8 == 0) goto LAB_00483fa0;
          uVar2 = 0xd39;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,0x44,"s3_clnt.c",uVar2);
        uVar2 = 0x50;
        goto LAB_00483e80;
      }
      uVar5 = 0xa5;
      uVar2 = 0xd24;
    }
    else {
      uVar5 = 0xaa;
      uVar2 = 0xd1e;
    }
  }
LAB_00483e68:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x82,uVar5,"s3_clnt.c",uVar2);
  uVar2 = 0x28;
LAB_00483e80:
  ssl3_send_alert(param_1,2,uVar2);
  return 0;
}

