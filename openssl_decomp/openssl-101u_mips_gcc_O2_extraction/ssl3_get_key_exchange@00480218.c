
int ssl3_get_key_exchange(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  ushort *puVar3;
  byte *pbVar4;
  ushort *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined *puVar10;
  uint uVar11;
  int iVar12;
  undefined *puVar13;
  uint uVar14;
  ushort *puVar15;
  uint uVar16;
  int *piVar17;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined4 local_d0;
  int local_cc;
  int local_c8;
  undefined auStack_c4 [24];
  undefined auStack_ac [128];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar10 = auStack_c4;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puVar10);
  iVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x1140,0x1141,0xffffffff,param_1[0x42],&local_cc)
  ;
  if (local_cc == 0) goto LAB_004802ec;
  iVar7 = param_1[0x16];
  uVar11 = *(uint *)(*(int *)(iVar7 + 0x344) + 0xc);
  if (*(int *)(iVar7 + 0x340) != 0xc) {
    if ((uVar11 & 0x88) == 0) {
      if ((uVar11 & 0x100) != 0) {
        puVar10 = (undefined *)param_1[0x30];
        uVar6 = (*(code *)PTR_ssl_sess_cert_new_006a7fec)();
        iVar2 = param_1[0x39];
        *(undefined4 *)(puVar10 + 0x98) = uVar6;
        if (*(int *)(iVar2 + 0x14c) != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          iVar2 = param_1[0x39];
        }
        iVar7 = param_1[0x16];
        *(undefined4 *)(iVar2 + 0x14c) = 0;
      }
      iVar2 = 1;
      *(undefined4 *)(iVar7 + 0x354) = 1;
      goto LAB_004802ec;
    }
    iVar7 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0xf4,"s3_clnt.c",0x538);
    local_d8 = 0;
    piVar17 = (int *)0x0;
    local_d0 = 10;
    local_d4 = 0;
    local_dc = 0;
    goto LAB_00480a88;
  }
  iVar12 = param_1[0x30];
  iVar7 = *(int *)(iVar12 + 0x98);
  puVar15 = (ushort *)param_1[0x10];
  if (iVar7 == 0) {
    uVar6 = (*(code *)PTR_ssl_sess_cert_new_006a7fec)();
    *(undefined4 *)(iVar12 + 0x98) = uVar6;
  }
  else {
    if (*(int *)(iVar7 + 0x6c) != 0) {
      (*(code *)PTR_RSA_free_006a7600)();
      iVar7 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar7 + 0x6c) = 0;
    }
    if (*(int *)(iVar7 + 0x70) != 0) {
      (*(code *)PTR_DH_free_006a7508)();
      iVar7 = *(int *)(param_1[0x30] + 0x98);
      *(undefined4 *)(iVar7 + 0x70) = 0;
    }
    if (*(int *)(iVar7 + 0x74) != 0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
      *(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = 0;
    }
  }
  local_d0 = 0x32;
  uVar14 = *(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x10);
  if ((uVar11 & 0x100) != 0) {
    if (iVar2 < 2) {
      uVar9 = 0xa0;
      uVar6 = 0x570;
      goto LAB_00480c10;
    }
    uVar11 = (uint)*puVar15;
    if (0x80 < uVar11) {
      uVar9 = 0x92;
      uVar6 = 0x57d;
      local_d0 = 0x28;
      goto LAB_00480c10;
    }
    if (iVar2 + -2 < (int)uVar11) {
      uVar9 = 0x13c;
      uVar6 = 0x582;
      goto LAB_00480c10;
    }
    iVar12 = param_1[0x30];
    uVar6 = (*(code *)PTR_BUF_strndup_006a7fcc)(puVar15 + 1,uVar11);
    iVar7 = param_1[0x30];
    *(undefined4 *)(iVar12 + 0x8c) = uVar6;
    iVar2 = iVar2 - (uVar11 + 2);
    if (*(int *)(iVar7 + 0x8c) == 0) {
      uVar9 = 0x41;
      uVar6 = 0x58a;
      local_d0 = 0x28;
      goto LAB_00480c10;
    }
LAB_00480424:
    piVar17 = (int *)0x0;
    if (iVar2 == 0) {
LAB_00480430:
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puVar10);
      iVar2 = 1;
      goto LAB_004802ec;
    }
    uVar9 = 0x99;
    uVar6 = 0x79d;
LAB_00480acc:
    iVar7 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
    local_d8 = 0;
    local_d4 = 0;
    local_dc = 0;
    goto LAB_00480a88;
  }
  if ((uVar11 & 0x400) == 0) {
    if ((uVar11 & 1) != 0) {
      if ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) == 0) {
        uVar6 = 0x601;
LAB_00480bfc:
        uVar9 = 0xf4;
        local_d0 = 10;
        goto LAB_00480c10;
      }
      iVar7 = (*(code *)PTR_RSA_new_006a787c)();
      if (iVar7 == 0) {
        uVar9 = 0x41;
        uVar6 = 0x605;
        goto LAB_00480644;
      }
      if (iVar2 < 2) {
        uVar9 = 0xa0;
        uVar6 = 0x60b;
LAB_00481208:
        piVar17 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
      }
      else {
        uVar11 = (uint)*puVar15;
        if (iVar2 + -2 < (int)uVar11) {
          uVar9 = 0x79;
          uVar6 = 0x611;
          goto LAB_00481208;
        }
        iVar12 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar15 + 1,uVar11,*(undefined4 *)(iVar7 + 0x10))
        ;
        *(int *)(iVar7 + 0x10) = iVar12;
        if (iVar12 == 0) {
          uVar9 = 3;
          uVar6 = 0x617;
          goto LAB_00481300;
        }
        puVar5 = (ushort *)((int)(puVar15 + 1) + uVar11);
        if ((int)(iVar2 - (uVar11 + 2)) < 2) {
          uVar9 = 0xa0;
          uVar6 = 0x61d;
          goto LAB_00481208;
        }
        puVar3 = puVar5 + 1;
        uVar16 = (uint)*puVar5;
        if ((int)(iVar2 - (uVar11 + 4)) < (int)uVar16) {
          uVar9 = 0x78;
          uVar6 = 0x625;
          goto LAB_00481208;
        }
        local_e0 = uVar11 + 4 + uVar16;
        iVar12 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar3,uVar16,*(undefined4 *)(iVar7 + 0x14));
        *(int *)(iVar7 + 0x14) = iVar12;
        if (iVar12 == 0) {
          uVar9 = 3;
          uVar6 = 0x62b;
LAB_00481300:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(0);
          goto LAB_00481254;
        }
        puVar3 = (ushort *)((int)puVar3 + uVar16);
        iVar2 = iVar2 - local_e0;
        if ((uVar14 & 1) == 0) {
          uVar9 = 0x44;
          uVar6 = 0x637;
          goto LAB_00481300;
        }
        piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                   (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
        iVar12 = (*(code *)PTR_EVP_PKEY_bits_006a6fe4)(piVar17);
        iVar8 = 0x200;
        if ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 8) == 0) {
          iVar8 = 0x400;
        }
        if (iVar8 < iVar12) {
          *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x6c) = iVar7;
          goto LAB_0048084c;
        }
        local_d0 = 10;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0xf4,"s3_clnt.c",0x63d);
      }
      ssl3_send_alert(param_1,2,local_d0);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
LAB_00481254:
      (*(code *)PTR_RSA_free_006a7600)(iVar7);
      (*(code *)PTR_BN_CTX_free_006a7954)(0);
      (*(code *)PTR_EC_POINT_free_006a7fac)(0);
      while( true ) {
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(puVar10);
        iVar2 = -1;
        param_1[0xd] = 5;
LAB_004802ec:
        if (local_2c == *(int *)puVar1) break;
        uVar6 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004813ac:
        uVar9 = 0xeb;
        local_d0 = 0x2f;
LAB_00480c10:
        iVar7 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
        piVar17 = (int *)0x0;
        local_d8 = 0;
        local_d4 = 0;
        local_dc = 0;
LAB_00480a88:
        ssl3_send_alert(param_1,2,local_d0);
        (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
LAB_0048067c:
        if (local_dc != 0) {
          (*(code *)PTR_DH_free_006a7508)();
        }
        (*(code *)PTR_BN_CTX_free_006a7954)(local_d4);
        (*(code *)PTR_EC_POINT_free_006a7fac)(local_d8);
        if (iVar7 != 0) {
          (*(code *)PTR_EC_KEY_free_006a71d4)(iVar7);
        }
      }
      return iVar2;
    }
    if ((uVar11 & 8) != 0) {
      local_dc = (*(code *)PTR_DH_new_006a751c)();
      if (local_dc == 0) {
        uVar9 = 5;
        uVar6 = 0x64a;
      }
      else {
        if (iVar2 < 2) {
          uVar9 = 0xa0;
          uVar6 = 0x650;
LAB_004814e4:
          iVar7 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
          piVar17 = (int *)0x0;
          local_d8 = 0;
          local_d4 = 0;
          goto LAB_00480a88;
        }
        uVar11 = (uint)*puVar15;
        if (iVar2 + -2 < (int)uVar11) {
          uVar9 = 0x6e;
          uVar6 = 0x656;
          goto LAB_004814e4;
        }
        iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar15 + 1,uVar11,0);
        *(int *)(local_dc + 8) = iVar7;
        if (iVar7 == 0) {
          uVar9 = 3;
          uVar6 = 0x65c;
        }
        else {
          puVar3 = (ushort *)((int)(puVar15 + 1) + uVar11);
          if (*(int *)(iVar7 + 4) == 0) {
            uVar9 = 0x18b;
            uVar6 = 0x662;
            goto LAB_004814e4;
          }
          if ((int)(iVar2 - (uVar11 + 2)) < 2) {
            uVar9 = 0xa0;
            uVar6 = 0x668;
            goto LAB_004814e4;
          }
          puVar5 = puVar3 + 1;
          uVar16 = (uint)*puVar3;
          if ((int)(iVar2 - (uVar11 + 4)) < (int)uVar16) {
            uVar9 = 0x6c;
            uVar6 = 0x670;
            goto LAB_004814e4;
          }
          iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar5,uVar16,0);
          iVar12 = uVar11 + 4 + uVar16;
          *(int *)(local_dc + 0xc) = iVar7;
          if (iVar7 == 0) {
            uVar9 = 3;
            uVar6 = 0x676;
          }
          else {
            puVar5 = (ushort *)((int)puVar5 + uVar16);
            if (*(int *)(iVar7 + 4) == 0) {
              uVar9 = 0x177;
              uVar6 = 0x67c;
              goto LAB_004814e4;
            }
            if (iVar2 - iVar12 < 2) {
              uVar9 = 0xa0;
              uVar6 = 0x681;
              goto LAB_004814e4;
            }
            iVar12 = iVar12 + 2;
            puVar3 = puVar5 + 1;
            uVar11 = (uint)*puVar5;
            local_e0 = iVar12 + uVar11;
            if (iVar2 - iVar12 < (int)uVar11) {
              uVar9 = 0x6d;
              uVar6 = 0x689;
              goto LAB_004814e4;
            }
            iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar3,uVar11,0);
            *(int *)(local_dc + 0x14) = iVar7;
            if (iVar7 != 0) {
              puVar3 = (ushort *)((int)puVar3 + uVar11);
              iVar2 = iVar2 - local_e0;
              if (*(int *)(iVar7 + 4) == 0) {
                uVar9 = 0x189;
                uVar6 = 0x696;
                goto LAB_004814e4;
              }
              if ((uVar14 & 1) == 0) {
                if ((uVar14 & 2) == 0) {
                  piVar17 = (int *)0x0;
                }
                else {
                  piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                             (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x24)
                                             );
                }
              }
              else {
                piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                           (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
              }
              *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x70) = local_dc;
              goto LAB_0048084c;
            }
            uVar9 = 3;
            uVar6 = 0x68f;
          }
        }
      }
      iVar7 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
      piVar17 = (int *)0x0;
      local_d8 = 0;
      goto LAB_00480668;
    }
    uVar6 = 0x6b0;
    if ((uVar11 & 6) != 0) goto LAB_004813ac;
    if ((uVar11 & 0x80) != 0) {
      iVar7 = (*(code *)PTR_EC_KEY_new_006a71a8)();
      if (iVar7 == 0) {
        uVar9 = 0x41;
        uVar6 = 0x6bb;
      }
      else {
        if (iVar2 < 4) {
          uVar6 = 0xa0;
          uVar9 = 0x6cc;
LAB_004812c4:
          piVar17 = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar6,"s3_clnt.c",uVar9);
          local_d8 = 0;
          local_d4 = 0;
          local_dc = 0;
          goto LAB_00480a88;
        }
        if ((*(char *)puVar15 != '\x03') ||
           (iVar12 = tls1_ec_curve_id2nid(*(char *)(puVar15 + 1)), iVar12 == 0)) {
          uVar6 = 0x13a;
          uVar9 = 0x6d4;
          local_d0 = 0x50;
          goto LAB_004812c4;
        }
        iVar12 = (*(code *)PTR_EC_GROUP_new_by_curve_name_006a7184)(iVar12);
        if (iVar12 == 0) {
          uVar9 = 0x10;
          uVar6 = 0x6da;
        }
        else {
          iVar8 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar7,iVar12);
          if (iVar8 != 0) {
            (*(code *)PTR_EC_GROUP_free_006a719c)(iVar12);
            uVar6 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar7);
            if (((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0x20) & 2) != 0) &&
               (iVar12 = (*(code *)PTR_EC_GROUP_get_degree_006a7ae0)(uVar6), 0xa3 < iVar12)) {
              uVar6 = 0x136;
              uVar9 = 0x6e9;
              local_d0 = 0x3c;
              goto LAB_004812c4;
            }
            local_d8 = (*(code *)PTR_EC_POINT_new_006a7fc0)(uVar6);
            if ((local_d8 == 0) || (local_d4 = (*(code *)PTR_BN_CTX_new_006a794c)(), local_d4 == 0))
            {
              piVar17 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x41,"s3_clnt.c",0x6f2);
              local_dc = 0;
              goto LAB_00480668;
            }
            uVar11 = (uint)*(byte *)((int)puVar15 + 3);
            if ((iVar2 + -4 < (int)uVar11) ||
               (iVar12 = (*(code *)PTR_EC_POINT_oct2point_006a7fc8)
                                   (uVar6,local_d8,puVar15 + 2,uVar11,local_d4), iVar12 == 0)) {
              piVar17 = (int *)0x0;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x132,"s3_clnt.c",0x6fc);
              local_dc = 0;
              goto LAB_00480a88;
            }
            local_e0 = uVar11 + 4;
            iVar2 = iVar2 - local_e0;
            puVar3 = (ushort *)((int)(puVar15 + 2) + uVar11);
            if ((uVar14 & 1) == 0) {
              if ((uVar14 & 0x40) == 0) {
                piVar17 = (int *)0x0;
              }
              else {
                piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                           (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x48));
              }
            }
            else {
              piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
            }
            (*(code *)PTR_EC_KEY_set_public_key_006a8068)(iVar7,local_d8);
            puVar13 = PTR_BN_CTX_free_006a7954;
            *(int *)(*(int *)(param_1[0x30] + 0x98) + 0x74) = iVar7;
            (*(code *)puVar13)(local_d4);
            (*(code *)PTR_EC_POINT_free_006a7fac)(local_d8);
            goto LAB_0048084c;
          }
          uVar9 = 0x10;
          uVar6 = 0x6de;
        }
      }
      piVar17 = (int *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
      local_d8 = 0;
      local_dc = 0;
      goto LAB_00480668;
    }
    if (uVar11 != 0) {
      uVar6 = 0x720;
      goto LAB_00480bfc;
    }
LAB_00480628:
    if ((uVar14 & 0x404) != 0) goto LAB_00480424;
    uVar9 = 0x44;
    uVar6 = 0x798;
  }
  else {
    if (iVar2 < 2) {
      uVar9 = 0xa0;
      uVar6 = 0x596;
      goto LAB_00480c10;
    }
    uVar11 = (uint)*puVar15;
    if (iVar2 + -2 < (int)uVar11) {
      uVar9 = 0x15e;
      uVar6 = 0x59c;
      goto LAB_00480c10;
    }
    iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar15 + 1,uVar11,0);
    param_1[0x6a] = iVar7;
    if (iVar7 == 0) {
      uVar9 = 3;
      uVar6 = 0x5a2;
    }
    else {
      puVar3 = (ushort *)((int)(puVar15 + 1) + uVar11);
      if ((int)(iVar2 - (uVar11 + 2)) < 2) {
        uVar9 = 0xa0;
        uVar6 = 0x5a8;
        goto LAB_00480c10;
      }
      puVar5 = puVar3 + 1;
      uVar16 = (uint)*puVar3;
      if ((int)(iVar2 - (uVar11 + 4)) < (int)uVar16) {
        uVar9 = 0x15d;
        uVar6 = 0x5b0;
        goto LAB_00480c10;
      }
      iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar5,uVar16,0);
      iVar12 = uVar11 + 4 + uVar16;
      param_1[0x6b] = iVar7;
      if (iVar7 == 0) {
        uVar9 = 3;
        uVar6 = 0x5b6;
      }
      else {
        pbVar4 = (byte *)((int)puVar5 + uVar16);
        if (iVar2 - iVar12 < 1) {
          uVar9 = 0xa0;
          uVar6 = 0x5bc;
          goto LAB_00480c10;
        }
        iVar12 = iVar12 + 1;
        uVar11 = (uint)*pbVar4;
        pbVar4 = pbVar4 + 1;
        if (iVar2 - iVar12 < (int)uVar11) {
          uVar9 = 0x15f;
          uVar6 = 0x5c5;
          goto LAB_00480c10;
        }
        iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(pbVar4,uVar11,0);
        iVar12 = iVar12 + uVar11;
        param_1[0x6c] = iVar7;
        if (iVar7 == 0) {
          uVar9 = 3;
          uVar6 = 0x5cb;
        }
        else {
          puVar3 = (ushort *)(pbVar4 + uVar11);
          if (iVar2 - iVar12 < 2) {
            uVar9 = 0xa0;
            uVar6 = 0x5d1;
            goto LAB_00480c10;
          }
          iVar12 = iVar12 + 2;
          uVar11 = (uint)*puVar3;
          local_e0 = iVar12 + uVar11;
          if (iVar2 - iVar12 < (int)uVar11) {
            uVar9 = 0x15c;
            uVar6 = 0x5d9;
            goto LAB_00480c10;
          }
          iVar7 = (*(code *)PTR_BN_bin2bn_006a7904)(puVar3 + 1,uVar11,0);
          param_1[0x6d] = iVar7;
          if (iVar7 != 0) {
            puVar3 = (ushort *)((int)(puVar3 + 1) + uVar11);
            iVar7 = (*(code *)PTR_srp_verify_server_param_006a8060)(param_1,&local_d0);
            iVar2 = iVar2 - local_e0;
            if (iVar7 == 0) {
              uVar9 = 0x173;
              uVar6 = 0x5e6;
              goto LAB_00480c10;
            }
            if ((uVar14 & 1) == 0) {
              if ((uVar14 & 2) == 0) goto LAB_00480628;
              piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0x24));
            }
            else {
              piVar17 = (int *)(*(code *)PTR_X509_get_pubkey_006a6f08)
                                         (*(undefined4 *)(*(int *)(param_1[0x30] + 0x98) + 0xc));
            }
LAB_0048084c:
            if (piVar17 != (int *)0x0) {
              if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
                if (iVar2 < 2) {
                  uVar9 = 0xa0;
                  uVar6 = 0x72c;
                  goto LAB_00480acc;
                }
                uVar11 = tls12_get_sigid(piVar17);
                if (uVar11 == 0xffffffff) {
                  iVar7 = 0;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x44,"s3_clnt.c",0x733);
                  local_d8 = 0;
                  local_dc = 0;
                  goto LAB_00480668;
                }
                if (uVar11 != *(byte *)((int)puVar3 + 1)) {
                  iVar7 = 0;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x172,"s3_clnt.c",0x739);
                  local_d8 = 0;
                  local_d0 = 0x32;
                  local_d4 = 0;
                  local_dc = 0;
                  goto LAB_00480a88;
                }
                iVar7 = tls12_get_hash(*(byte *)puVar3);
                if (iVar7 == 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x170,"s3_clnt.c",0x73f);
                  local_d8 = 0;
                  local_d4 = 0;
                  local_dc = 0;
                  goto LAB_00480a88;
                }
                puVar3 = puVar3 + 1;
                iVar2 = iVar2 + -2;
              }
              else {
                iVar7 = (*(code *)PTR_EVP_sha1_006a75d0)();
              }
              if (1 < iVar2) {
                uVar11 = (uint)*puVar3;
                iVar12 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(piVar17);
                if (((uVar11 != iVar2 - 2U) || (iVar12 < (int)uVar11)) || (uVar11 == 0)) {
                  uVar9 = 0x108;
                  uVar6 = 0x757;
                  goto LAB_00480acc;
                }
                if ((*piVar17 != 6) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
                  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(puVar10,iVar7,0);
                  if ((iVar2 < 1) ||
                     (((iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                          (puVar10,param_1[0x16] + 0xc0,0x20), iVar2 < 1 ||
                       (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                          (puVar10,param_1[0x16] + 0xa0,0x20), iVar2 < 1)) ||
                      (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(puVar10,puVar15,local_e0),
                      iVar2 < 1)))) {
                    uVar9 = 6;
                    uVar6 = 0x78b;
                    local_d0 = 0x50;
                  }
                  else {
                    iVar2 = (*(code *)PTR_EVP_VerifyFinal_006a7fdc)
                                      (puVar10,puVar3 + 1,uVar11,piVar17);
                    if (0 < iVar2) goto LAB_00480430;
                    uVar9 = 0x7b;
                    uVar6 = 0x791;
                    local_d0 = 0x33;
                  }
                  goto LAB_00480acc;
                }
                local_d8 = 0;
                iVar2 = 2;
                puVar13 = auStack_ac;
                do {
                  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(puVar10,8);
                  if (iVar2 == 2) {
                    uVar6 = *(undefined4 *)(param_1[0x39] + 0x8c);
                  }
                  else {
                    uVar6 = *(undefined4 *)(param_1[0x39] + 0x90);
                  }
                  iVar7 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(puVar10,uVar6,0);
                  if ((((iVar7 < 1) ||
                       (iVar7 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                          (puVar10,param_1[0x16] + 0xc0,0x20), iVar7 < 1)) ||
                      (iVar7 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                         (puVar10,param_1[0x16] + 0xa0,0x20), iVar7 < 1)) ||
                     ((iVar7 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(puVar10,puVar15,local_e0),
                      iVar7 < 1 ||
                      (iVar7 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(puVar10,puVar13,&local_c8)
                      , iVar7 < 1)))) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,0x44,"s3_clnt.c",0x76e);
                    local_d0 = 0x50;
                    goto LAB_00480a78;
                  }
                  iVar2 = iVar2 + -1;
                  puVar13 = puVar13 + local_c8;
                  local_d8 = local_d8 + local_c8;
                } while (iVar2 != 0);
                iVar2 = (*(code *)PTR_RSA_verify_006a7a7c)
                                  (0x72,auStack_ac,local_d8,puVar3 + 1,uVar11,piVar17[5]);
                if (iVar2 < 0) {
                  uVar6 = 0x76;
                  uVar9 = 0x778;
LAB_00480a5c:
                  local_d0 = 0x33;
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar6,"s3_clnt.c",uVar9);
LAB_00480a78:
                  iVar7 = 0;
                  local_d8 = 0;
                  local_d4 = 0;
                  local_dc = 0;
                  goto LAB_00480a88;
                }
                if (iVar2 == 0) {
                  uVar6 = 0x7b;
                  uVar9 = 0x77e;
                  goto LAB_00480a5c;
                }
                goto LAB_00480430;
              }
              uVar9 = 0xa0;
              uVar6 = 0x74b;
              goto LAB_00480acc;
            }
            goto LAB_00480628;
          }
          uVar9 = 3;
          uVar6 = 0x5df;
        }
      }
    }
  }
LAB_00480644:
  iVar7 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x8d,uVar9,"s3_clnt.c",uVar6);
  piVar17 = (int *)0x0;
  local_d8 = 0;
  local_dc = 0;
LAB_00480668:
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar17);
  local_d4 = 0;
  goto LAB_0048067c;
}

