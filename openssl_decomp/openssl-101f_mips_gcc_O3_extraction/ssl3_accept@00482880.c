
undefined1 * ssl3_accept(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined *puVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  undefined4 uVar15;
  code *pcVar16;
  int iVar17;
  int local_40;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_34,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  pcVar16 = (code *)param_1[0x34];
  *puVar4 = 0;
  puVar11 = PTR_SSL_state_006a88f4;
  if (pcVar16 == (code *)0x0) {
    pcVar16 = *(code **)(param_1[0x39] + 0x9c);
  }
  param_1[7] = param_1[7] + 1;
  uVar5 = (*(code *)puVar11)(param_1);
  if (((uVar5 & 0x3000) == 0) ||
     (uVar5 = (*(code *)PTR_SSL_state_006a88f4)(param_1), (uVar5 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a88d4)(param_1);
  }
  if (param_1[0x26] == 0) {
    uVar15 = 0xb3;
    uVar9 = 0xec;
LAB_004836dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,uVar15,"s3_srvr.c",uVar9);
    puVar7 = (undefined1 *)0xffffffff;
LAB_00482bc0:
    if (local_2c == *(int *)puVar3) {
      return puVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (local_2c == 0x300) {
      return SSLv3_client_method_data_16530;
    }
    return (undefined1 *)0x0;
  }
  if (param_1[0x62] != 0) {
    param_1[0x62] = 0;
    param_1[99] = param_1[99] + 1;
  }
  bVar1 = param_1[0xd] < 0x2182;
  iVar17 = param_1[0xd];
LAB_004829a0:
  if (!bVar1) goto LAB_00482a4c;
LAB_004829ac:
  puVar11 = PTR_BIO_ctrl_006a7f18;
  if (iVar17 < 0x2180) {
    if (iVar17 < 0x2132) {
      if (0x212f < iVar17) {
        puVar7 = (undefined1 *)ssl3_send_server_hello(param_1);
        if (0 < (int)puVar7) {
          if (param_1[0x1b] != 0) goto LAB_004831ec;
          puVar14 = (uint *)param_1[0x16];
          param_1[0x11] = 0;
          param_1[0xd] = 0x2140;
          goto LAB_00482a2c;
        }
        goto LAB_00482b90;
      }
      if (0x2112 < iVar17) {
        if (0x211f < iVar17) {
          if (iVar17 < 0x2122) {
            param_1[0xc] = 0;
            if (iVar17 == 0x2120) {
              puVar11 = *(undefined **)(param_1[0xf] + 4);
              *puVar11 = 0;
              puVar11[1] = 0;
              puVar11[2] = 0;
              puVar11[3] = 0;
              param_1[0x12] = 0;
              param_1[0xd] = 0x2121;
              param_1[0x11] = 4;
            }
            puVar7 = (undefined1 *)ssl3_do_write(param_1,0x16);
            if (0 < (int)puVar7) {
              *(undefined4 *)(param_1[0x16] + 0x350) = 0x2122;
              param_1[0x11] = 0;
              param_1[0xd] = 0x2100;
              ssl3_init_finished_mac(param_1);
              puVar14 = (uint *)param_1[0x16];
              goto LAB_00482a2c;
            }
            goto LAB_00482b90;
          }
          if (iVar17 == 0x2122) {
            puVar14 = (uint *)param_1[0x16];
            param_1[0xd] = 3;
            goto LAB_00482a2c;
          }
        }
        goto LAB_00483214;
      }
      if (0x210f < iVar17) {
        param_1[0xc] = 0;
        if ((param_1[6] != 4) &&
           (puVar7 = (undefined1 *)ssl3_get_client_hello(param_1), (int)puVar7 < 1))
        goto LAB_00482b90;
        puVar14 = (uint *)param_1[0x16];
        local_30 = 0x70;
        if (((*(uint *)(puVar14[0xd1] + 0xc) & 0x400) == 0) || (param_1[0x66] == 0)) {
LAB_0048339c:
          param_1[0x11] = 0;
          param_1[100] = 2;
          param_1[0xd] = 0x2130;
          goto LAB_00482a2c;
        }
        if (param_1[0x69] == 0) {
          local_30 = 0x73;
        }
        else {
          puVar7 = (undefined1 *)
                   (*(code *)PTR_SSL_srp_server_param_with_username_006a9188)(param_1,&local_30);
          if ((int)puVar7 < 0) {
            param_1[6] = 4;
            goto LAB_00482b90;
          }
          if (puVar7 == (undefined1 *)0x0) {
            puVar14 = (uint *)param_1[0x16];
            goto LAB_0048339c;
          }
        }
        ssl3_send_alert(param_1,2,local_30);
        if (local_30 == 0x73) goto LAB_00482b8c;
        uVar15 = 0xe2;
        uVar9 = 0x177;
LAB_00483220:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,uVar15,"s3_srvr.c",uVar9);
        puVar7 = (undefined1 *)0xffffffff;
        goto LAB_00482b90;
      }
      if (iVar17 == 0x2000) goto LAB_00482ebc;
      if (iVar17 < 0x2001) {
        if (iVar17 != 3) goto LAB_00483214;
        ssl3_cleanup_key_block(param_1);
        (*(code *)PTR_BUF_MEM_free_006a8594)(param_1[0xf]);
        puVar11 = PTR_ssl_free_wbio_buffer_006a9024;
        param_1[0xf] = 0;
        (*(code *)puVar11)(param_1);
        param_1[0x11] = 0;
        puVar11 = PTR_ssl_update_cache_006a9028;
        if (param_1[100] != 2) {
          puVar7 = (undefined1 *)0x1;
          goto LAB_00482b90;
        }
        param_1[100] = 0;
        param_1[10] = 0;
        (*(code *)puVar11)(param_1,2);
        *(int *)(param_1[0x39] + 0x48) = *(int *)(param_1[0x39] + 0x48) + 1;
        param_1[8] = (int)ssl3_accept;
        if (pcVar16 == (code *)0x0) {
          puVar7 = (undefined1 *)0x1;
          param_1[7] = param_1[7] + -1;
          goto LAB_00482bc0;
        }
        (*pcVar16)(param_1,0x20,1);
        puVar7 = (undefined1 *)0x1;
        param_1[7] = param_1[7] + -1;
        goto LAB_00482ba0;
      }
      if (iVar17 == 0x2003) goto LAB_00482ebc;
      if (iVar17 == 0x2100) {
        param_1[6] = 2;
        iVar6 = (*(code *)puVar11)(param_1[4],0xb,0,0);
        if (0 < iVar6) {
          puVar14 = (uint *)param_1[0x16];
          param_1[6] = 1;
          param_1[0xd] = puVar14[0xd4];
          goto LAB_00482a2c;
        }
LAB_00482b8c:
        puVar7 = (undefined1 *)0xffffffff;
        goto LAB_00482b90;
      }
    }
    else if (iVar17 < 0x2152) {
      if (0x214f < iVar17) {
        iVar6 = param_1[0x16];
        uVar5 = param_1[0x40];
        uVar12 = *(uint *)(*(int *)(iVar6 + 0x344) + 0xc);
        *(uint *)(iVar6 + 0x370) = (uint)((uVar5 & 0x200000) != 0);
        if ((((uVar5 & 0x200000) == 0) &&
            (((uVar12 & 0x100) == 0 || (*(int *)(param_1[0x39] + 0x14c) == 0)))) &&
           ((uVar12 & 0x48e) == 0)) {
          bVar2 = true;
          if ((uVar12 & 1) != 0) {
            if (*(int *)(param_1[0x26] + 0x34) == 0) goto LAB_00483448;
            bVar2 = true;
            if ((*(uint *)(*(int *)(iVar6 + 0x344) + 0x20) & 2) != 0) {
              iVar10 = (*(code *)PTR_EVP_PKEY_size_006a85f4)();
              iVar6 = param_1[0x16];
              iVar13 = 0x200;
              if ((*(uint *)(*(int *)(iVar6 + 0x344) + 0x20) & 8) == 0) {
                iVar13 = 0x400;
              }
              if (iVar13 < iVar10 << 3) goto LAB_00483448;
              bVar2 = true;
            }
          }
        }
        else {
LAB_00483448:
          puVar7 = (undefined1 *)ssl3_send_server_key_exchange(param_1);
          if ((int)puVar7 < 1) goto LAB_00482b90;
          iVar6 = param_1[0x16];
          bVar2 = false;
        }
        param_1[0x11] = 0;
        param_1[0xd] = 0x2160;
LAB_00482d1c:
        if (*(int *)(iVar6 + 0x354) != 0) goto LAB_00482a38;
        if (!bVar2) goto LAB_00482c70;
        iVar17 = param_1[0xd];
        goto LAB_00482a40;
      }
      if (iVar17 - 0x2140U < 2) {
        iVar6 = param_1[0x16];
        uVar5 = *(uint *)(*(int *)(iVar6 + 0x344) + 0x10);
        if ((((uVar5 & 4) == 0) && ((*(uint *)(*(int *)(iVar6 + 0x344) + 0xc) & 0x100) == 0)) &&
           ((uVar5 & 0x20) == 0)) {
          if (iVar17 == 0x2140) {
            iVar6 = (*(code *)PTR_ssl_get_server_send_cert_006a915c)(param_1);
            if ((iVar6 == 0) &&
               ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x10) != 0x20 ||
                ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc) & 0x10) != 0)))) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9a,0x44,"s3_srvr.c",0xd0a);
              puVar7 = (undefined1 *)0x0;
              goto LAB_00482b90;
            }
            iVar6 = ssl3_output_cert_chain(param_1,iVar6);
            param_1[0x11] = iVar6;
            param_1[0x12] = 0;
            param_1[0xd] = 0x2141;
          }
          puVar7 = (undefined1 *)ssl3_do_write(param_1,0x16);
          if ((int)puVar7 < 1) goto LAB_00482b90;
          iVar6 = param_1[0x16];
          if (param_1[0x4b] == 0) {
            bVar2 = false;
            param_1[0xd] = 0x2150;
          }
          else {
            bVar2 = false;
            param_1[0xd] = 0x2200;
          }
        }
        else {
          bVar2 = true;
          param_1[0xd] = 0x2150;
        }
        param_1[0x11] = 0;
        goto LAB_00482d1c;
      }
    }
    else {
      if (iVar17 < 0x2160) goto LAB_00483214;
      if (iVar17 < 0x2162) {
        uVar5 = param_1[0x32];
        if (((uVar5 & 1) == 0) || ((*(int *)(param_1[0x30] + 0x9c) != 0 && ((uVar5 & 4) != 0)))) {
          iVar6 = param_1[0x16];
        }
        else {
          iVar6 = param_1[0x16];
          uVar12 = *(uint *)(*(int *)(iVar6 + 0x344) + 0x10);
          if (((((uVar12 & 4) == 0) || ((uVar5 & 2) != 0)) && ((uVar12 & 0x20) == 0)) &&
             ((*(uint *)(*(int *)(iVar6 + 0x344) + 0xc) & 0x100) == 0)) {
            *(undefined4 *)(iVar6 + 0x390) = 1;
            puVar7 = (undefined1 *)ssl3_send_certificate_request(param_1);
            if (0 < (int)puVar7) {
              puVar14 = (uint *)param_1[0x16];
              param_1[0xd] = 0x2100;
              puVar14[0xd4] = 0x2180;
              param_1[0x11] = 0;
              goto LAB_00482a2c;
            }
            goto LAB_00482b90;
          }
        }
        iVar17 = *(int *)(iVar6 + 0x178);
        *(undefined4 *)(iVar6 + 0x390) = 0;
        param_1[0xd] = 0x2170;
        if (iVar17 != 0) {
          iVar17 = ssl3_digest_cached_records(param_1);
          if (iVar17 != 0) goto LAB_00482a38;
LAB_004831c8:
          puVar7 = (undefined1 *)0xffffffff;
          goto LAB_00482bc0;
        }
        iVar17 = 0x2170;
        bVar1 = true;
      }
      if (iVar17 - 0x2170U < 2) {
        if (iVar17 == 0x2170) {
          puVar11 = *(undefined **)(param_1[0xf] + 4);
          *puVar11 = 0xe;
          puVar11[1] = 0;
          puVar11[2] = 0;
          puVar11[3] = 0;
          param_1[0x12] = 0;
          param_1[0xd] = 0x2171;
          param_1[0x11] = 4;
        }
        puVar7 = (undefined1 *)ssl3_do_write(param_1,0x16);
        if (0 < (int)puVar7) {
          puVar14 = (uint *)param_1[0x16];
          puVar14[0xd4] = 0x2180;
          param_1[0x11] = 0;
          param_1[0xd] = 0x2100;
          goto LAB_00482a2c;
        }
        goto LAB_00482b90;
      }
    }
LAB_00483214:
    uVar15 = 0xff;
    uVar9 = 0x32e;
    goto LAB_00483220;
  }
  puVar7 = (undefined1 *)ssl3_check_client_hello(param_1);
  if (0 < (int)puVar7) {
    puVar14 = (uint *)param_1[0x16];
    if (puVar7 == (undefined1 *)0x2) {
      param_1[0xd] = 0x2112;
      goto LAB_00482a2c;
    }
    if (puVar14[0xe4] != 0) {
      puVar7 = (undefined1 *)ssl3_get_client_certificate(param_1);
      if ((int)puVar7 < 1) goto LAB_00482b90;
      puVar14 = (uint *)param_1[0x16];
    }
    param_1[0x11] = 0;
    param_1[0xd] = 0x2190;
LAB_00482a2c:
    uVar5 = puVar14[0xd5];
    do {
      if (uVar5 == 0) {
LAB_00482c70:
        if ((param_1[0x3a] != 0) &&
           (puVar7 = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a7f18)(param_1[4],0xb,0,0),
           (int)puVar7 < 1)) {
          iVar17 = param_1[7];
          goto LAB_00482b94;
        }
        if (pcVar16 != (code *)0x0) {
          iVar6 = param_1[0xd];
          if (iVar6 != iVar17) {
            param_1[0xd] = iVar17;
            (*pcVar16)(param_1,0x2001,1);
            bVar1 = iVar6 < 0x2182;
            param_1[0xd] = iVar6;
            iVar17 = iVar6;
          }
          goto LAB_004829a0;
        }
      }
LAB_00482a38:
      iVar17 = param_1[0xd];
LAB_00482a40:
      bVar1 = iVar17 < 0x2182;
      if (bVar1) goto LAB_004829ac;
LAB_00482a4c:
      if (iVar17 < 0x21e2) {
        if (0x21df < iVar17) {
          puVar7 = (undefined1 *)
                   ssl3_send_finished(param_1,0x21e0,0x21e1,
                                      *(undefined4 *)(*(int *)(param_1[2] + 100) + 0x28),
                                      *(undefined4 *)(*(int *)(param_1[2] + 100) + 0x2c));
          if ((int)puVar7 < 1) break;
          puVar14 = (uint *)param_1[0x16];
          param_1[0xd] = 0x2100;
          if (param_1[0x1b] == 0) {
            puVar14[0xd4] = 3;
            param_1[0x11] = 0;
          }
          else if (puVar14[0x107] == 0) {
            puVar14[0xd4] = 0x21c0;
            param_1[0x11] = 0;
          }
          else {
            puVar14[0xd4] = 0x2210;
            param_1[0x11] = 0;
          }
          goto LAB_00482a2c;
        }
        if (0x21a1 < iVar17) {
          if (iVar17 < 0x21c0) goto LAB_00483214;
          if (iVar17 < 0x21c2) {
            puVar7 = (undefined1 *)ssl3_get_finished(param_1,0x21c0,0x21c1);
            if ((int)puVar7 < 1) break;
            if (param_1[0x1b] == 0) {
LAB_004831ec:
              if (param_1[0x50] == 0) {
                puVar14 = (uint *)param_1[0x16];
                param_1[0x11] = 0;
                param_1[0xd] = 0x21d0;
              }
              else {
                puVar14 = (uint *)param_1[0x16];
                param_1[0x11] = 0;
                param_1[0xd] = 0x21f0;
              }
            }
            else {
              puVar14 = (uint *)param_1[0x16];
              param_1[0xd] = 3;
              param_1[0x11] = 0;
            }
            goto LAB_00482a2c;
          }
          if (1 < iVar17 - 0x21d0U) goto LAB_00483214;
          pcVar8 = *(code **)(*(int *)(param_1[2] + 100) + 8);
          *(undefined4 *)(param_1[0x30] + 0xb4) = *(undefined4 *)(param_1[0x16] + 0x344);
          iVar6 = (*pcVar8)(param_1);
          if (iVar6 == 0) goto LAB_00482b8c;
          puVar7 = (undefined1 *)ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
          if ((int)puVar7 < 1) break;
          param_1[0x11] = 0;
          param_1[0xd] = 0x21e0;
          iVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0x10))(param_1,0x22);
          if (iVar6 == 0) goto LAB_00482b8c;
LAB_00482dd0:
          puVar14 = (uint *)param_1[0x16];
          goto LAB_00482a2c;
        }
        if (iVar17 < 0x21a0) {
          if (1 < iVar17 - 0x2190U) goto LAB_00483214;
          puVar7 = (undefined1 *)ssl3_get_client_key_exchange(param_1);
          if ((int)puVar7 < 1) break;
          if (puVar7 != (undefined1 *)0x2) {
            if ((*param_1 >> 8 == 3) && (0x302 < *param_1)) {
              param_1[0x11] = 0;
              param_1[0xd] = 0x21a0;
              if (*(int *)(param_1[0x30] + 0x9c) == 0) goto LAB_00482dd0;
              puVar14 = (uint *)param_1[0x16];
              if (puVar14[0x5e] == 0) {
                uVar15 = 0x44;
                uVar9 = 0x279;
                goto LAB_004836dc;
              }
              *puVar14 = *puVar14 | 0x20;
              iVar6 = ssl3_digest_cached_records(param_1);
              if (iVar6 == 0) goto LAB_004831c8;
              puVar14 = (uint *)param_1[0x16];
              goto LAB_00482a2c;
            }
            puVar14 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x21a0;
            if (puVar14[0x5e] != 0) {
              iVar6 = ssl3_digest_cached_records(param_1);
              if (iVar6 == 0) goto LAB_004831c8;
              puVar14 = (uint *)param_1[0x16];
            }
            iVar6 = 0;
            local_40 = 0;
            goto LAB_00482b00;
          }
        }
        else {
          puVar7 = (undefined1 *)ssl3_get_cert_verify(param_1);
          if ((int)puVar7 < 1) break;
        }
        puVar14 = (uint *)param_1[0x16];
        iVar6 = 0x2210;
        uVar5 = puVar14[0x107];
        param_1[0x11] = 0;
        if (uVar5 == 0) {
          iVar6 = 0x21c0;
        }
        param_1[0xd] = iVar6;
        goto LAB_00482a2c;
      }
      if (0x2211 < iVar17) {
        if ((iVar17 == 0x4000) || (iVar17 == 0x6000)) goto LAB_00482ebc;
        if (iVar17 == 0x3004) goto code_r0x00482eb4;
        goto LAB_00483214;
      }
      if (0x220f < iVar17) {
        puVar7 = (undefined1 *)ssl3_get_next_proto(param_1);
        if ((int)puVar7 < 1) break;
        puVar14 = (uint *)param_1[0x16];
        param_1[0x11] = 0;
        param_1[0xd] = 0x21c0;
        goto LAB_00482a2c;
      }
      if (iVar17 < 0x21f0) goto LAB_00483214;
      if (iVar17 < 0x21f2) goto LAB_00482ff4;
      if (1 < iVar17 - 0x2200U) goto LAB_00483214;
      puVar7 = (undefined1 *)ssl3_send_cert_status(param_1);
      if ((int)puVar7 < 1) break;
      param_1[0x11] = 0;
      param_1[0xd] = 0x2150;
      uVar5 = *(uint *)(param_1[0x16] + 0x354);
    } while( true );
  }
LAB_00482b90:
  iVar17 = param_1[7];
LAB_00482b94:
  param_1[7] = iVar17 + -1;
  if (pcVar16 == (code *)0x0) goto LAB_00482bc0;
LAB_00482ba0:
  (*pcVar16)(param_1,0x2002,puVar7);
  goto LAB_00482bc0;
LAB_00482b00:
  do {
    if (*(int *)(puVar14[0x5f] + iVar6) != 0) {
      pcVar8 = *(code **)(*(int *)(param_1[2] + 100) + 0x1c);
      uVar9 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
      uVar9 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar9);
      (*pcVar8)(param_1,uVar9,param_1[0x16] + local_40 + 0x1b4);
      uVar9 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)
                        (*(undefined4 *)(*(int *)(param_1[0x16] + 0x17c) + iVar6));
      iVar10 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar9);
      if (iVar10 < 0) goto LAB_00482b8c;
      puVar14 = (uint *)param_1[0x16];
      local_40 = local_40 + iVar10;
    }
    iVar6 = iVar6 + 4;
  } while (iVar6 != 0x18);
  goto LAB_00482a2c;
code_r0x00482eb4:
  param_1[100] = 1;
LAB_00482ebc:
  param_1[9] = 1;
  if (pcVar16 != (code *)0x0) {
    (*pcVar16)(param_1,0x10,1);
  }
  if (*param_1 >> 8 != 3) {
    uVar15 = 0x44;
    uVar9 = 0x110;
    goto LAB_004836dc;
  }
  param_1[1] = 0x2000;
  if (param_1[0xf] == 0) {
    iVar6 = (*(code *)PTR_BUF_MEM_new_006a859c)();
    if ((iVar6 == 0) || (iVar10 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(iVar6,0x4000), iVar10 == 0))
    goto LAB_00482b8c;
    param_1[0xf] = iVar6;
  }
  iVar6 = ssl3_setup_buffers(param_1);
  if (iVar6 == 0) goto LAB_00482b8c;
  puVar14 = (uint *)param_1[0x16];
  iVar6 = param_1[0xd];
  param_1[0x11] = 0;
  *puVar14 = *puVar14 & 0xffffffbf;
  if (iVar6 == 0x3004) {
    if ((puVar14[0x106] == 0) && (-1 < param_1[0x40] << 0xd)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,0x152,"s3_srvr.c",0x13f);
      ssl3_send_alert(param_1,2,0x28);
      puVar7 = (undefined1 *)0xffffffff;
      goto LAB_00482b90;
    }
    *(int *)(param_1[0x39] + 0x44) = *(int *)(param_1[0x39] + 0x44) + 1;
    param_1[0xd] = 0x2120;
  }
  else {
    iVar6 = (*(code *)PTR_ssl_init_wbio_buffer_006a9048)(param_1,1);
    if (iVar6 == 0) goto LAB_00482b8c;
    ssl3_init_finished_mac(param_1);
    param_1[0xd] = 0x2110;
    puVar14 = (uint *)param_1[0x16];
    *(int *)(param_1[0x39] + 0x40) = *(int *)(param_1[0x39] + 0x40) + 1;
  }
  goto LAB_00482a2c;
LAB_00482ff4:
  puVar7 = (undefined1 *)ssl3_send_newsession_ticket(param_1);
  if ((int)puVar7 < 1) goto LAB_00482b90;
  puVar14 = (uint *)param_1[0x16];
  param_1[0x11] = 0;
  param_1[0xd] = 0x21d0;
  goto LAB_00482a2c;
}

