
undefined1 * ssl3_get_next_proto(int param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  code *pcVar9;
  undefined4 uVar10;
  int iVar11;
  undefined *puVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  undefined4 uVar17;
  int unaff_s0;
  code *pcVar18;
  uint unaff_s2;
  byte *unaff_s3;
  char *unaff_s4;
  int iVar19;
  int iStack_80;
  undefined4 uStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  undefined *puStack_64;
  uint uStack_60;
  byte *pbStack_5c;
  char *pcStack_58;
  int local_20;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  piVar13 = *(int **)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x41c) == 0) {
    uVar10 = 0x164;
    param_1 = unaff_s0;
  }
  else {
    puVar5 = (undefined1 *)(**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2210,0x2211,0x43);
    if (local_20 == 0) goto LAB_00482794;
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x180) != 0) {
      bVar2 = 1 < (int)puVar5;
      puVar5 = (undefined1 *)0x0;
      if (bVar2) {
        unaff_s3 = *(byte **)(param_1 + 0x40);
        bVar1 = *unaff_s3;
        unaff_s2 = (uint)bVar1;
        if (((int)(unaff_s2 + 1) < *(int *)(param_1 + 0x44)) &&
           (unaff_s4 = "s\n", *(int *)(param_1 + 0x44) == unaff_s3[unaff_s2 + 1] + unaff_s2 + 2)) {
          iVar19 = (*(code *)PTR_CRYPTO_malloc_006a8108)(unaff_s2,"s3_srvr.c",0xdfd);
          *(int *)(param_1 + 0x174) = iVar19;
          if (iVar19 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x132,0x41,"s3_srvr.c");
            puVar5 = (undefined1 *)0x0;
          }
          else {
            (*(code *)PTR_memcpy_006aabf4)(iVar19,unaff_s3 + 1,unaff_s2);
            puVar5 = (undefined1 *)0x1;
            *(byte *)(param_1 + 0x178) = bVar1;
          }
        }
        else {
          puVar5 = (undefined1 *)0x0;
        }
      }
      goto LAB_00482794;
    }
    uVar10 = 0x163;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x132,uVar10,"s3_srvr.c");
  puVar5 = (undefined1 *)0xffffffff;
LAB_00482794:
  if (piVar13 == *(int **)puStack_64) {
    return puVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_68 = param_1;
  uStack_60 = unaff_s2;
  pbStack_5c = unaff_s3;
  pcStack_58 = unaff_s4;
  uStack_74 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&uStack_74,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  pcVar18 = (code *)piVar13[0x34];
  *puVar6 = 0;
  puVar12 = PTR_SSL_state_006a88f4;
  if (pcVar18 == (code *)0x0) {
    pcVar18 = *(code **)(piVar13[0x39] + 0x9c);
  }
  piVar13[7] = piVar13[7] + 1;
  uVar7 = (*(code *)puVar12)(piVar13);
  if (((uVar7 & 0x3000) == 0) ||
     (uVar7 = (*(code *)PTR_SSL_state_006a88f4)(piVar13), (uVar7 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a88d4)(piVar13);
  }
  if (piVar13[0x26] == 0) {
    uVar17 = 0xb3;
    uVar10 = 0xec;
LAB_004836dc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,uVar17,"s3_srvr.c",uVar10);
    puVar5 = (undefined1 *)0xffffffff;
LAB_00482bc0:
    if (iStack_6c == *(int *)puVar4) {
      return puVar5;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (iStack_6c == 0x300) {
      return SSLv3_client_method_data_16530;
    }
    return (undefined1 *)0x0;
  }
  if (piVar13[0x62] != 0) {
    piVar13[0x62] = 0;
    piVar13[99] = piVar13[99] + 1;
  }
  bVar2 = piVar13[0xd] < 0x2182;
  iVar19 = piVar13[0xd];
LAB_004829a0:
  if (!bVar2) goto LAB_00482a4c;
LAB_004829ac:
  puVar12 = PTR_BIO_ctrl_006a7f18;
  if (iVar19 < 0x2180) {
    if (iVar19 < 0x2132) {
      if (0x212f < iVar19) {
        puVar5 = (undefined1 *)ssl3_send_server_hello(piVar13);
        if (0 < (int)puVar5) {
          if (piVar13[0x1b] != 0) goto LAB_004831ec;
          puVar16 = (uint *)piVar13[0x16];
          piVar13[0x11] = 0;
          piVar13[0xd] = 0x2140;
          goto LAB_00482a2c;
        }
        goto LAB_00482b90;
      }
      if (0x2112 < iVar19) {
        if (0x211f < iVar19) {
          if (iVar19 < 0x2122) {
            piVar13[0xc] = 0;
            if (iVar19 == 0x2120) {
              puVar12 = *(undefined **)(piVar13[0xf] + 4);
              *puVar12 = 0;
              puVar12[1] = 0;
              puVar12[2] = 0;
              puVar12[3] = 0;
              piVar13[0x12] = 0;
              piVar13[0xd] = 0x2121;
              piVar13[0x11] = 4;
            }
            puVar5 = (undefined1 *)ssl3_do_write(piVar13,0x16);
            if (0 < (int)puVar5) {
              *(undefined4 *)(piVar13[0x16] + 0x350) = 0x2122;
              piVar13[0x11] = 0;
              piVar13[0xd] = 0x2100;
              ssl3_init_finished_mac(piVar13);
              puVar16 = (uint *)piVar13[0x16];
              goto LAB_00482a2c;
            }
            goto LAB_00482b90;
          }
          if (iVar19 == 0x2122) {
            puVar16 = (uint *)piVar13[0x16];
            piVar13[0xd] = 3;
            goto LAB_00482a2c;
          }
        }
        goto LAB_00483214;
      }
      if (0x210f < iVar19) {
        piVar13[0xc] = 0;
        if ((piVar13[6] != 4) &&
           (puVar5 = (undefined1 *)ssl3_get_client_hello(piVar13), (int)puVar5 < 1))
        goto LAB_00482b90;
        puVar16 = (uint *)piVar13[0x16];
        iStack_70 = 0x70;
        if (((*(uint *)(puVar16[0xd1] + 0xc) & 0x400) == 0) || (piVar13[0x66] == 0)) {
LAB_0048339c:
          piVar13[0x11] = 0;
          piVar13[100] = 2;
          piVar13[0xd] = 0x2130;
          goto LAB_00482a2c;
        }
        if (piVar13[0x69] == 0) {
          iStack_70 = 0x73;
        }
        else {
          puVar5 = (undefined1 *)
                   (*(code *)PTR_SSL_srp_server_param_with_username_006a9188)(piVar13,&iStack_70);
          if ((int)puVar5 < 0) {
            piVar13[6] = 4;
            goto LAB_00482b90;
          }
          if (puVar5 == (undefined1 *)0x0) {
            puVar16 = (uint *)piVar13[0x16];
            goto LAB_0048339c;
          }
        }
        ssl3_send_alert(piVar13,2,iStack_70);
        if (iStack_70 == 0x73) goto LAB_00482b8c;
        uVar17 = 0xe2;
        uVar10 = 0x177;
LAB_00483220:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,uVar17,"s3_srvr.c",uVar10);
        puVar5 = (undefined1 *)0xffffffff;
        goto LAB_00482b90;
      }
      if (iVar19 == 0x2000) goto LAB_00482ebc;
      if (iVar19 < 0x2001) {
        if (iVar19 != 3) goto LAB_00483214;
        ssl3_cleanup_key_block(piVar13);
        (*(code *)PTR_BUF_MEM_free_006a8594)(piVar13[0xf]);
        puVar12 = PTR_ssl_free_wbio_buffer_006a9024;
        piVar13[0xf] = 0;
        (*(code *)puVar12)(piVar13);
        piVar13[0x11] = 0;
        puVar12 = PTR_ssl_update_cache_006a9028;
        if (piVar13[100] != 2) {
          puVar5 = (undefined1 *)0x1;
          goto LAB_00482b90;
        }
        piVar13[100] = 0;
        piVar13[10] = 0;
        (*(code *)puVar12)(piVar13,2);
        *(int *)(piVar13[0x39] + 0x48) = *(int *)(piVar13[0x39] + 0x48) + 1;
        piVar13[8] = (int)ssl3_accept;
        if (pcVar18 == (code *)0x0) {
          puVar5 = (undefined1 *)0x1;
          piVar13[7] = piVar13[7] + -1;
          goto LAB_00482bc0;
        }
        (*pcVar18)(piVar13,0x20,1);
        puVar5 = (undefined1 *)0x1;
        piVar13[7] = piVar13[7] + -1;
        goto LAB_00482ba0;
      }
      if (iVar19 == 0x2003) goto LAB_00482ebc;
      if (iVar19 == 0x2100) {
        piVar13[6] = 2;
        iVar8 = (*(code *)puVar12)(piVar13[4],0xb,0,0);
        if (0 < iVar8) {
          puVar16 = (uint *)piVar13[0x16];
          piVar13[6] = 1;
          piVar13[0xd] = puVar16[0xd4];
          goto LAB_00482a2c;
        }
LAB_00482b8c:
        puVar5 = (undefined1 *)0xffffffff;
        goto LAB_00482b90;
      }
    }
    else if (iVar19 < 0x2152) {
      if (0x214f < iVar19) {
        iVar8 = piVar13[0x16];
        uVar7 = piVar13[0x40];
        uVar14 = *(uint *)(*(int *)(iVar8 + 0x344) + 0xc);
        *(uint *)(iVar8 + 0x370) = (uint)((uVar7 & 0x200000) != 0);
        if ((((uVar7 & 0x200000) == 0) &&
            (((uVar14 & 0x100) == 0 || (*(int *)(piVar13[0x39] + 0x14c) == 0)))) &&
           ((uVar14 & 0x48e) == 0)) {
          bVar3 = true;
          if ((uVar14 & 1) != 0) {
            if (*(int *)(piVar13[0x26] + 0x34) == 0) goto LAB_00483448;
            bVar3 = true;
            if ((*(uint *)(*(int *)(iVar8 + 0x344) + 0x20) & 2) != 0) {
              iVar11 = (*(code *)PTR_EVP_PKEY_size_006a85f4)();
              iVar8 = piVar13[0x16];
              iVar15 = 0x200;
              if ((*(uint *)(*(int *)(iVar8 + 0x344) + 0x20) & 8) == 0) {
                iVar15 = 0x400;
              }
              if (iVar15 < iVar11 << 3) goto LAB_00483448;
              bVar3 = true;
            }
          }
        }
        else {
LAB_00483448:
          puVar5 = (undefined1 *)ssl3_send_server_key_exchange(piVar13);
          if ((int)puVar5 < 1) goto LAB_00482b90;
          iVar8 = piVar13[0x16];
          bVar3 = false;
        }
        piVar13[0x11] = 0;
        piVar13[0xd] = 0x2160;
LAB_00482d1c:
        if (*(int *)(iVar8 + 0x354) != 0) goto LAB_00482a38;
        if (!bVar3) goto LAB_00482c70;
        iVar19 = piVar13[0xd];
        goto LAB_00482a40;
      }
      if (iVar19 - 0x2140U < 2) {
        iVar8 = piVar13[0x16];
        uVar7 = *(uint *)(*(int *)(iVar8 + 0x344) + 0x10);
        if ((((uVar7 & 4) == 0) && ((*(uint *)(*(int *)(iVar8 + 0x344) + 0xc) & 0x100) == 0)) &&
           ((uVar7 & 0x20) == 0)) {
          if (iVar19 == 0x2140) {
            iVar8 = (*(code *)PTR_ssl_get_server_send_cert_006a915c)(piVar13);
            if ((iVar8 == 0) &&
               ((*(int *)(*(int *)(piVar13[0x16] + 0x344) + 0x10) != 0x20 ||
                ((*(uint *)(*(int *)(piVar13[0x16] + 0x344) + 0xc) & 0x10) != 0)))) {
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9a,0x44,"s3_srvr.c",0xd0a);
              puVar5 = (undefined1 *)0x0;
              goto LAB_00482b90;
            }
            iVar8 = ssl3_output_cert_chain(piVar13,iVar8);
            piVar13[0x11] = iVar8;
            piVar13[0x12] = 0;
            piVar13[0xd] = 0x2141;
          }
          puVar5 = (undefined1 *)ssl3_do_write(piVar13,0x16);
          if ((int)puVar5 < 1) goto LAB_00482b90;
          iVar8 = piVar13[0x16];
          if (piVar13[0x4b] == 0) {
            bVar3 = false;
            piVar13[0xd] = 0x2150;
          }
          else {
            bVar3 = false;
            piVar13[0xd] = 0x2200;
          }
        }
        else {
          bVar3 = true;
          piVar13[0xd] = 0x2150;
        }
        piVar13[0x11] = 0;
        goto LAB_00482d1c;
      }
    }
    else {
      if (iVar19 < 0x2160) goto LAB_00483214;
      if (iVar19 < 0x2162) {
        uVar7 = piVar13[0x32];
        if (((uVar7 & 1) == 0) || ((*(int *)(piVar13[0x30] + 0x9c) != 0 && ((uVar7 & 4) != 0)))) {
          iVar8 = piVar13[0x16];
        }
        else {
          iVar8 = piVar13[0x16];
          uVar14 = *(uint *)(*(int *)(iVar8 + 0x344) + 0x10);
          if (((((uVar14 & 4) == 0) || ((uVar7 & 2) != 0)) && ((uVar14 & 0x20) == 0)) &&
             ((*(uint *)(*(int *)(iVar8 + 0x344) + 0xc) & 0x100) == 0)) {
            *(undefined4 *)(iVar8 + 0x390) = 1;
            puVar5 = (undefined1 *)ssl3_send_certificate_request(piVar13);
            if (0 < (int)puVar5) {
              puVar16 = (uint *)piVar13[0x16];
              piVar13[0xd] = 0x2100;
              puVar16[0xd4] = 0x2180;
              piVar13[0x11] = 0;
              goto LAB_00482a2c;
            }
            goto LAB_00482b90;
          }
        }
        iVar19 = *(int *)(iVar8 + 0x178);
        *(undefined4 *)(iVar8 + 0x390) = 0;
        piVar13[0xd] = 0x2170;
        if (iVar19 != 0) {
          iVar19 = ssl3_digest_cached_records(piVar13);
          if (iVar19 != 0) goto LAB_00482a38;
LAB_004831c8:
          puVar5 = (undefined1 *)0xffffffff;
          goto LAB_00482bc0;
        }
        iVar19 = 0x2170;
        bVar2 = true;
      }
      if (iVar19 - 0x2170U < 2) {
        if (iVar19 == 0x2170) {
          puVar12 = *(undefined **)(piVar13[0xf] + 4);
          *puVar12 = 0xe;
          puVar12[1] = 0;
          puVar12[2] = 0;
          puVar12[3] = 0;
          piVar13[0x12] = 0;
          piVar13[0xd] = 0x2171;
          piVar13[0x11] = 4;
        }
        puVar5 = (undefined1 *)ssl3_do_write(piVar13,0x16);
        if (0 < (int)puVar5) {
          puVar16 = (uint *)piVar13[0x16];
          puVar16[0xd4] = 0x2180;
          piVar13[0x11] = 0;
          piVar13[0xd] = 0x2100;
          goto LAB_00482a2c;
        }
        goto LAB_00482b90;
      }
    }
LAB_00483214:
    uVar17 = 0xff;
    uVar10 = 0x32e;
    goto LAB_00483220;
  }
  puVar5 = (undefined1 *)ssl3_check_client_hello(piVar13);
  if (0 < (int)puVar5) {
    puVar16 = (uint *)piVar13[0x16];
    if (puVar5 == (undefined1 *)0x2) {
      piVar13[0xd] = 0x2112;
      goto LAB_00482a2c;
    }
    if (puVar16[0xe4] != 0) {
      puVar5 = (undefined1 *)ssl3_get_client_certificate(piVar13);
      if ((int)puVar5 < 1) goto LAB_00482b90;
      puVar16 = (uint *)piVar13[0x16];
    }
    piVar13[0x11] = 0;
    piVar13[0xd] = 0x2190;
LAB_00482a2c:
    uVar7 = puVar16[0xd5];
    do {
      if (uVar7 == 0) {
LAB_00482c70:
        if ((piVar13[0x3a] != 0) &&
           (puVar5 = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a7f18)(piVar13[4],0xb,0,0),
           (int)puVar5 < 1)) {
          iVar19 = piVar13[7];
          goto LAB_00482b94;
        }
        if (pcVar18 != (code *)0x0) {
          iVar8 = piVar13[0xd];
          if (iVar8 != iVar19) {
            piVar13[0xd] = iVar19;
            (*pcVar18)(piVar13,0x2001,1);
            bVar2 = iVar8 < 0x2182;
            piVar13[0xd] = iVar8;
            iVar19 = iVar8;
          }
          goto LAB_004829a0;
        }
      }
LAB_00482a38:
      iVar19 = piVar13[0xd];
LAB_00482a40:
      bVar2 = iVar19 < 0x2182;
      if (bVar2) goto LAB_004829ac;
LAB_00482a4c:
      if (iVar19 < 0x21e2) {
        if (0x21df < iVar19) {
          puVar5 = (undefined1 *)
                   ssl3_send_finished(piVar13,0x21e0,0x21e1,
                                      *(undefined4 *)(*(int *)(piVar13[2] + 100) + 0x28),
                                      *(undefined4 *)(*(int *)(piVar13[2] + 100) + 0x2c));
          if ((int)puVar5 < 1) break;
          puVar16 = (uint *)piVar13[0x16];
          piVar13[0xd] = 0x2100;
          if (piVar13[0x1b] == 0) {
            puVar16[0xd4] = 3;
            piVar13[0x11] = 0;
          }
          else if (puVar16[0x107] == 0) {
            puVar16[0xd4] = 0x21c0;
            piVar13[0x11] = 0;
          }
          else {
            puVar16[0xd4] = 0x2210;
            piVar13[0x11] = 0;
          }
          goto LAB_00482a2c;
        }
        if (0x21a1 < iVar19) {
          if (iVar19 < 0x21c0) goto LAB_00483214;
          if (iVar19 < 0x21c2) {
            puVar5 = (undefined1 *)ssl3_get_finished(piVar13,0x21c0,0x21c1);
            if ((int)puVar5 < 1) break;
            if (piVar13[0x1b] == 0) {
LAB_004831ec:
              if (piVar13[0x50] == 0) {
                puVar16 = (uint *)piVar13[0x16];
                piVar13[0x11] = 0;
                piVar13[0xd] = 0x21d0;
              }
              else {
                puVar16 = (uint *)piVar13[0x16];
                piVar13[0x11] = 0;
                piVar13[0xd] = 0x21f0;
              }
            }
            else {
              puVar16 = (uint *)piVar13[0x16];
              piVar13[0xd] = 3;
              piVar13[0x11] = 0;
            }
            goto LAB_00482a2c;
          }
          if (1 < iVar19 - 0x21d0U) goto LAB_00483214;
          pcVar9 = *(code **)(*(int *)(piVar13[2] + 100) + 8);
          *(undefined4 *)(piVar13[0x30] + 0xb4) = *(undefined4 *)(piVar13[0x16] + 0x344);
          iVar8 = (*pcVar9)(piVar13);
          if (iVar8 == 0) goto LAB_00482b8c;
          puVar5 = (undefined1 *)ssl3_send_change_cipher_spec(piVar13,0x21d0,0x21d1);
          if ((int)puVar5 < 1) break;
          piVar13[0x11] = 0;
          piVar13[0xd] = 0x21e0;
          iVar8 = (**(code **)(*(int *)(piVar13[2] + 100) + 0x10))(piVar13,0x22);
          if (iVar8 == 0) goto LAB_00482b8c;
LAB_00482dd0:
          puVar16 = (uint *)piVar13[0x16];
          goto LAB_00482a2c;
        }
        if (iVar19 < 0x21a0) {
          if (1 < iVar19 - 0x2190U) goto LAB_00483214;
          puVar5 = (undefined1 *)ssl3_get_client_key_exchange(piVar13);
          if ((int)puVar5 < 1) break;
          if (puVar5 != (undefined1 *)0x2) {
            if ((*piVar13 >> 8 == 3) && (0x302 < *piVar13)) {
              piVar13[0x11] = 0;
              piVar13[0xd] = 0x21a0;
              if (*(int *)(piVar13[0x30] + 0x9c) == 0) goto LAB_00482dd0;
              puVar16 = (uint *)piVar13[0x16];
              if (puVar16[0x5e] == 0) {
                uVar17 = 0x44;
                uVar10 = 0x279;
                goto LAB_004836dc;
              }
              *puVar16 = *puVar16 | 0x20;
              iVar8 = ssl3_digest_cached_records(piVar13);
              if (iVar8 == 0) goto LAB_004831c8;
              puVar16 = (uint *)piVar13[0x16];
              goto LAB_00482a2c;
            }
            puVar16 = (uint *)piVar13[0x16];
            piVar13[0x11] = 0;
            piVar13[0xd] = 0x21a0;
            if (puVar16[0x5e] != 0) {
              iVar8 = ssl3_digest_cached_records(piVar13);
              if (iVar8 == 0) goto LAB_004831c8;
              puVar16 = (uint *)piVar13[0x16];
            }
            iVar8 = 0;
            iStack_80 = 0;
            goto LAB_00482b00;
          }
        }
        else {
          puVar5 = (undefined1 *)ssl3_get_cert_verify(piVar13);
          if ((int)puVar5 < 1) break;
        }
        puVar16 = (uint *)piVar13[0x16];
        iVar8 = 0x2210;
        uVar7 = puVar16[0x107];
        piVar13[0x11] = 0;
        if (uVar7 == 0) {
          iVar8 = 0x21c0;
        }
        piVar13[0xd] = iVar8;
        goto LAB_00482a2c;
      }
      if (0x2211 < iVar19) {
        if ((iVar19 == 0x4000) || (iVar19 == 0x6000)) goto LAB_00482ebc;
        if (iVar19 == 0x3004) goto code_r0x00482eb4;
        goto LAB_00483214;
      }
      if (0x220f < iVar19) {
        puVar5 = (undefined1 *)ssl3_get_next_proto(piVar13);
        if ((int)puVar5 < 1) break;
        puVar16 = (uint *)piVar13[0x16];
        piVar13[0x11] = 0;
        piVar13[0xd] = 0x21c0;
        goto LAB_00482a2c;
      }
      if (iVar19 < 0x21f0) goto LAB_00483214;
      if (iVar19 < 0x21f2) goto LAB_00482ff4;
      if (1 < iVar19 - 0x2200U) goto LAB_00483214;
      puVar5 = (undefined1 *)ssl3_send_cert_status(piVar13);
      if ((int)puVar5 < 1) break;
      piVar13[0x11] = 0;
      piVar13[0xd] = 0x2150;
      uVar7 = *(uint *)(piVar13[0x16] + 0x354);
    } while( true );
  }
LAB_00482b90:
  iVar19 = piVar13[7];
LAB_00482b94:
  piVar13[7] = iVar19 + -1;
  if (pcVar18 == (code *)0x0) goto LAB_00482bc0;
LAB_00482ba0:
  (*pcVar18)(piVar13,0x2002,puVar5);
  goto LAB_00482bc0;
LAB_00482b00:
  do {
    if (*(int *)(puVar16[0x5f] + iVar8) != 0) {
      pcVar9 = *(code **)(*(int *)(piVar13[2] + 100) + 0x1c);
      uVar10 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
      uVar10 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar10);
      (*pcVar9)(piVar13,uVar10,piVar13[0x16] + iStack_80 + 0x1b4);
      uVar10 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)
                         (*(undefined4 *)(*(int *)(piVar13[0x16] + 0x17c) + iVar8));
      iVar11 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar10);
      if (iVar11 < 0) goto LAB_00482b8c;
      puVar16 = (uint *)piVar13[0x16];
      iStack_80 = iStack_80 + iVar11;
    }
    iVar8 = iVar8 + 4;
  } while (iVar8 != 0x18);
  goto LAB_00482a2c;
code_r0x00482eb4:
  piVar13[100] = 1;
LAB_00482ebc:
  piVar13[9] = 1;
  if (pcVar18 != (code *)0x0) {
    (*pcVar18)(piVar13,0x10,1);
  }
  if (*piVar13 >> 8 != 3) {
    uVar17 = 0x44;
    uVar10 = 0x110;
    goto LAB_004836dc;
  }
  piVar13[1] = 0x2000;
  if (piVar13[0xf] == 0) {
    iVar8 = (*(code *)PTR_BUF_MEM_new_006a859c)();
    if ((iVar8 == 0) || (iVar11 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(iVar8,0x4000), iVar11 == 0))
    goto LAB_00482b8c;
    piVar13[0xf] = iVar8;
  }
  iVar8 = ssl3_setup_buffers(piVar13);
  if (iVar8 == 0) goto LAB_00482b8c;
  puVar16 = (uint *)piVar13[0x16];
  iVar8 = piVar13[0xd];
  piVar13[0x11] = 0;
  *puVar16 = *puVar16 & 0xffffffbf;
  if (iVar8 == 0x3004) {
    if ((puVar16[0x106] == 0) && (-1 < piVar13[0x40] << 0xd)) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x80,0x152,"s3_srvr.c",0x13f);
      ssl3_send_alert(piVar13,2,0x28);
      puVar5 = (undefined1 *)0xffffffff;
      goto LAB_00482b90;
    }
    *(int *)(piVar13[0x39] + 0x44) = *(int *)(piVar13[0x39] + 0x44) + 1;
    piVar13[0xd] = 0x2120;
  }
  else {
    iVar8 = (*(code *)PTR_ssl_init_wbio_buffer_006a9048)(piVar13,1);
    if (iVar8 == 0) goto LAB_00482b8c;
    ssl3_init_finished_mac(piVar13);
    piVar13[0xd] = 0x2110;
    puVar16 = (uint *)piVar13[0x16];
    *(int *)(piVar13[0x39] + 0x40) = *(int *)(piVar13[0x39] + 0x40) + 1;
  }
  goto LAB_00482a2c;
LAB_00482ff4:
  puVar5 = (undefined1 *)ssl3_send_newsession_ticket(piVar13);
  if ((int)puVar5 < 1) goto LAB_00482b90;
  puVar16 = (uint *)piVar13[0x16];
  piVar13[0x11] = 0;
  piVar13[0xd] = 0x21d0;
  goto LAB_00482a2c;
}

