
int ssl3_get_next_proto(int param_1)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined *puVar11;
  int *piVar12;
  int iVar13;
  uint *puVar14;
  code *pcVar15;
  uint unaff_s2;
  byte *unaff_s3;
  char *unaff_s4;
  int iVar16;
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
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  piVar12 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x41c) == 0) {
    uVar9 = 0x164;
  }
  else {
    iVar5 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2210,0x2211,0x43);
    if (local_20 == 0) goto LAB_0047de60;
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x180) != 0) {
      if (1 < iVar5) {
        unaff_s3 = *(byte **)(param_1 + 0x40);
        bVar1 = *unaff_s3;
        unaff_s2 = (uint)bVar1;
        if (((int)(unaff_s2 + 1) < *(int *)(param_1 + 0x44)) &&
           (unaff_s4 = "-check_ss_sig",
           *(int *)(param_1 + 0x44) == unaff_s3[unaff_s2 + 1] + unaff_s2 + 2)) {
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2,"s3_srvr.c",0xe38);
          *(int *)(param_1 + 0x174) = iVar5;
          if (iVar5 != 0) {
            (*(code *)PTR_memcpy_006a9aec)(iVar5,unaff_s3 + 1,unaff_s2);
            iVar5 = 1;
            *(byte *)(param_1 + 0x178) = bVar1;
            goto LAB_0047de60;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x132,0x41,"s3_srvr.c");
        }
      }
      iVar5 = 0;
      *(undefined4 *)(param_1 + 0x34) = 5;
      goto LAB_0047de60;
    }
    uVar9 = 0x163;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x132,uVar9,"s3_srvr.c");
  iVar5 = -1;
  *(undefined4 *)(param_1 + 0x34) = 5;
LAB_0047de60:
  if (piVar12 == *(int **)puStack_64) {
    return iVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_68 = param_1;
  uStack_60 = unaff_s2;
  pbStack_5c = unaff_s3;
  pcStack_58 = unaff_s4;
  uStack_74 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&uStack_74,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  pcVar15 = (code *)piVar12[0x34];
  *puVar6 = 0;
  puVar11 = PTR_SSL_state_006a7808;
  if (pcVar15 == (code *)0x0) {
    pcVar15 = *(code **)(piVar12[0x39] + 0x9c);
  }
  piVar12[7] = piVar12[7] + 1;
  uVar7 = (*(code *)puVar11)(piVar12);
  if (((uVar7 & 0x3000) == 0) ||
     (uVar7 = (*(code *)PTR_SSL_state_006a7808)(piVar12), (uVar7 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a77e8)(piVar12);
  }
  if (piVar12[0x26] == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xb3,"s3_srvr.c",0xeb);
    iVar5 = -1;
    goto LAB_0047e298;
  }
  if (piVar12[0x62] != 0) {
    piVar12[0x62] = 0;
    piVar12[99] = piVar12[99] + 1;
  }
  bVar2 = piVar12[0xd] < 0x2182;
  iVar16 = piVar12[0xd];
LAB_0047e070:
  if (!bVar2) goto LAB_0047e11c;
LAB_0047e07c:
  puVar11 = PTR_BIO_ctrl_006a6e18;
  if (0x217f < iVar16) {
    iVar5 = ssl3_check_client_hello(piVar12);
    if (iVar5 < 1) goto LAB_0047e268;
    puVar14 = (uint *)piVar12[0x16];
    if (iVar5 == 2) {
      piVar12[0xd] = 0x2112;
      goto LAB_0047e0fc;
    }
    if (puVar14[0xe4] != 0) {
      iVar5 = ssl3_get_client_certificate(piVar12);
      if (iVar5 < 1) goto LAB_0047e268;
      puVar14 = (uint *)piVar12[0x16];
    }
    piVar12[0x11] = 0;
    piVar12[0xd] = 0x2190;
    goto LAB_0047e0fc;
  }
  if (iVar16 < 0x2132) {
    if (0x212f < iVar16) {
      iVar5 = ssl3_send_server_hello(piVar12);
      if (iVar5 < 1) goto LAB_0047e268;
      if (piVar12[0x1b] != 0) goto LAB_0047e914;
      puVar14 = (uint *)piVar12[0x16];
      piVar12[0x11] = 0;
      piVar12[0xd] = 0x2140;
      goto LAB_0047e0fc;
    }
    if (iVar16 < 0x2113) {
      if (0x210f < iVar16) {
        piVar12[0xc] = 0;
        if ((piVar12[6] != 4) && (iVar5 = ssl3_get_client_hello(piVar12), iVar5 < 1))
        goto LAB_0047e268;
        puVar14 = (uint *)piVar12[0x16];
        iStack_70 = 0x70;
        if (((*(uint *)(puVar14[0xd1] + 0xc) & 0x400) != 0) && (piVar12[0x66] != 0)) {
          if (piVar12[0x69] == 0) {
            iStack_70 = 0x73;
            goto LAB_0047ec04;
          }
          iVar5 = (*(code *)PTR_SSL_srp_server_param_with_username_006a8028)(piVar12,&iStack_70);
          if (iVar5 < 0) {
            piVar12[6] = 4;
            goto LAB_0047e268;
          }
          if (iVar5 != 0) goto LAB_0047ec04;
          puVar14 = (uint *)piVar12[0x16];
        }
        piVar12[0x11] = 0;
        piVar12[100] = 2;
        piVar12[0xd] = 0x2130;
        goto LAB_0047e0fc;
      }
      if (iVar16 == 0x2000) goto LAB_0047e5b8;
      if (iVar16 < 0x2001) {
        if (iVar16 == 3) {
          ssl3_cleanup_key_block(piVar12);
          (*(code *)PTR_BUF_MEM_free_006a7494)(piVar12[0xf]);
          puVar11 = PTR_ssl_free_wbio_buffer_006a801c;
          piVar12[0xf] = 0;
          (*(code *)puVar11)(piVar12);
          piVar12[0x11] = 0;
          puVar11 = PTR_ssl_update_cache_006a802c;
          if (piVar12[100] != 2) {
            iVar5 = 1;
            goto LAB_0047e268;
          }
          piVar12[100] = 0;
          piVar12[10] = 0;
          (*(code *)puVar11)(piVar12,2);
          *(int *)(piVar12[0x39] + 0x48) = *(int *)(piVar12[0x39] + 0x48) + 1;
          piVar12[8] = (int)ssl3_accept;
          if (pcVar15 != (code *)0x0) {
            (*pcVar15)(piVar12,0x20,1);
            iVar5 = 1;
            piVar12[7] = piVar12[7] + -1;
            goto LAB_0047e278;
          }
          iVar5 = 1;
          piVar12[7] = piVar12[7] + -1;
          goto LAB_0047e298;
        }
      }
      else {
        if (iVar16 == 0x2003) goto LAB_0047e5b8;
        if (iVar16 == 0x2100) {
          piVar12[6] = 2;
          iVar5 = (*(code *)puVar11)(piVar12[4],0xb,0,0);
          if (iVar5 < 1) {
            iVar5 = -1;
            goto LAB_0047e268;
          }
          puVar14 = (uint *)piVar12[0x16];
          piVar12[6] = 1;
          piVar12[0xd] = puVar14[0xd4];
          goto LAB_0047e0fc;
        }
      }
    }
    else if (0x211f < iVar16) {
      if (iVar16 < 0x2122) {
        piVar12[0xc] = 0;
        if (iVar16 == 0x2120) {
          puVar11 = *(undefined **)(piVar12[0xf] + 4);
          *puVar11 = 0;
          puVar11[1] = 0;
          puVar11[2] = 0;
          puVar11[3] = 0;
          piVar12[0x12] = 0;
          piVar12[0xd] = 0x2121;
          piVar12[0x11] = 4;
        }
        iVar5 = ssl3_do_write(piVar12,0x16);
        if (iVar5 < 1) goto LAB_0047e268;
        *(undefined4 *)(piVar12[0x16] + 0x350) = 0x2122;
        piVar12[0x11] = 0;
        piVar12[0xd] = 0x2100;
        ssl3_init_finished_mac(piVar12);
        puVar14 = (uint *)piVar12[0x16];
        goto LAB_0047e0fc;
      }
      if (iVar16 == 0x2122) {
        puVar14 = (uint *)piVar12[0x16];
        piVar12[0xd] = 3;
        goto LAB_0047e0fc;
      }
    }
    goto LAB_0047e938;
  }
  if (0x2151 < iVar16) {
    if (iVar16 < 0x2160) goto LAB_0047e938;
    if (iVar16 < 0x2162) {
      uVar7 = piVar12[0x32];
      if (((uVar7 & 1) == 0) || ((*(int *)(piVar12[0x30] + 0x9c) != 0 && ((uVar7 & 4) != 0)))) {
        iVar5 = piVar12[0x16];
      }
      else {
        iVar5 = piVar12[0x16];
        iVar10 = *(int *)(iVar5 + 0x344);
        if (((((*(uint *)(iVar10 + 0x10) & 4) == 0) || ((uVar7 & 2) != 0)) &&
            ((*(uint *)(iVar10 + 0x10) & 0x420) == 0)) && ((*(uint *)(iVar10 + 0xc) & 0x100) == 0))
        {
          *(undefined4 *)(iVar5 + 0x390) = 1;
          iVar5 = ssl3_send_certificate_request(piVar12);
          if (iVar5 < 1) goto LAB_0047e268;
          puVar14 = (uint *)piVar12[0x16];
          piVar12[0xd] = 0x2100;
          puVar14[0xd4] = 0x2180;
          piVar12[0x11] = 0;
          goto LAB_0047e0fc;
        }
      }
      iVar16 = *(int *)(iVar5 + 0x178);
      *(undefined4 *)(iVar5 + 0x390) = 0;
      piVar12[0xd] = 0x2170;
      if (iVar16 != 0) {
        iVar5 = ssl3_digest_cached_records(piVar12);
        if (iVar5 == 0) {
LAB_0047ecb4:
          iVar5 = -1;
          piVar12[0xd] = 5;
          goto LAB_0047e298;
        }
        iVar16 = piVar12[0xd];
        bVar2 = iVar16 < 0x2182;
        goto LAB_0047e110;
      }
      iVar16 = 0x2170;
      bVar2 = true;
    }
    if (iVar16 - 0x2170U < 2) {
      if (iVar16 == 0x2170) {
        puVar11 = *(undefined **)(piVar12[0xf] + 4);
        *puVar11 = 0xe;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11[3] = 0;
        piVar12[0x12] = 0;
        piVar12[0xd] = 0x2171;
        piVar12[0x11] = 4;
      }
      iVar5 = ssl3_do_write(piVar12,0x16);
      if (iVar5 < 1) goto LAB_0047e268;
      puVar14 = (uint *)piVar12[0x16];
      puVar14[0xd4] = 0x2180;
      piVar12[0x11] = 0;
      piVar12[0xd] = 0x2100;
      goto LAB_0047e0fc;
    }
LAB_0047e938:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xff,"s3_srvr.c",0x364);
    iVar5 = -1;
    goto LAB_0047e268;
  }
  if (iVar16 < 0x2150) {
    if (1 < iVar16 - 0x2140U) goto LAB_0047e938;
    iVar5 = piVar12[0x16];
    if (((*(uint *)(*(int *)(iVar5 + 0x344) + 0x10) & 0x424) == 0) &&
       ((*(uint *)(*(int *)(iVar5 + 0x344) + 0xc) & 0x100) == 0)) {
      if (iVar16 == 0x2140) {
        iVar5 = (*(code *)PTR_ssl_get_server_send_cert_006a7ff0)(piVar12);
        if ((iVar5 == 0) &&
           ((*(int *)(*(int *)(piVar12[0x16] + 0x344) + 0x10) != 0x20 ||
            ((*(uint *)(*(int *)(piVar12[0x16] + 0x344) + 0xc) & 0x10) != 0)))) {
          uVar9 = 0xd1b;
LAB_0047eeb4:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9a,0x44,"s3_srvr.c",uVar9);
          piVar12[0xd] = 5;
          iVar5 = 0;
          goto LAB_0047e268;
        }
        iVar5 = ssl3_output_cert_chain(piVar12,iVar5);
        if (iVar5 == 0) {
          uVar9 = 0xd23;
          goto LAB_0047eeb4;
        }
        piVar12[0x11] = iVar5;
        piVar12[0x12] = 0;
        piVar12[0xd] = 0x2141;
      }
      iVar5 = ssl3_do_write(piVar12,0x16);
      if (iVar5 < 1) goto LAB_0047e268;
      iVar5 = piVar12[0x16];
      if (piVar12[0x4b] == 0) {
        bVar3 = false;
        piVar12[0xd] = 0x2150;
      }
      else {
        bVar3 = false;
        piVar12[0xd] = 0x2200;
      }
    }
    else {
      bVar3 = true;
      piVar12[0xd] = 0x2150;
    }
    piVar12[0x11] = 0;
  }
  else {
    iVar5 = piVar12[0x16];
    uVar7 = *(uint *)(*(int *)(iVar5 + 0x344) + 0xc);
    *(undefined4 *)(iVar5 + 0x370) = 0;
    if ((((uVar7 & 0x100) == 0) || (*(int *)(piVar12[0x39] + 0x14c) == 0)) && ((uVar7 & 0x48e) == 0)
       ) {
      bVar3 = true;
      if ((uVar7 & 1) != 0) {
        if (*(int *)(piVar12[0x26] + 0x34) == 0) goto LAB_0047e9bc;
        bVar3 = true;
        if ((*(uint *)(*(int *)(iVar5 + 0x344) + 0x20) & 2) != 0) {
          iVar10 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
          iVar5 = piVar12[0x16];
          iVar13 = 0x200;
          if ((*(uint *)(*(int *)(iVar5 + 0x344) + 0x20) & 8) == 0) {
            iVar13 = 0x400;
          }
          if (iVar13 < iVar10 << 3) goto LAB_0047e9bc;
          bVar3 = true;
        }
      }
    }
    else {
LAB_0047e9bc:
      iVar5 = ssl3_send_server_key_exchange(piVar12);
      if (iVar5 < 1) goto LAB_0047e268;
      iVar5 = piVar12[0x16];
      bVar3 = false;
    }
    piVar12[0x11] = 0;
    piVar12[0xd] = 0x2160;
  }
  if (*(int *)(iVar5 + 0x354) != 0) goto LAB_0047e108;
  if (!bVar3) goto LAB_0047e348;
  iVar16 = piVar12[0xd];
  bVar2 = iVar16 < 0x2182;
LAB_0047e110:
  if (bVar2) goto LAB_0047e07c;
LAB_0047e11c:
  if (0x21e1 < iVar16) {
    if (0x2211 < iVar16) {
      if ((iVar16 != 0x4000) && (iVar16 != 0x6000)) {
        if (iVar16 != 0x3004) goto LAB_0047e938;
        piVar12[100] = 1;
      }
LAB_0047e5b8:
      piVar12[9] = 1;
      if (pcVar15 != (code *)0x0) {
        (*pcVar15)(piVar12,0x10,1);
      }
      if (*piVar12 >> 8 == 3) {
        piVar12[1] = 0x2000;
        if (piVar12[0xf] == 0) {
          iVar5 = (*(code *)PTR_BUF_MEM_new_006a749c)();
          if (iVar5 == 0) goto LAB_0047e25c;
          iVar10 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar5,0x4000);
          if (iVar10 == 0) {
            (*(code *)PTR_BUF_MEM_free_006a7494)(iVar5);
            goto LAB_0047e25c;
          }
          piVar12[0xf] = iVar5;
        }
        iVar5 = ssl3_setup_buffers(piVar12);
        if (iVar5 == 0) goto LAB_0047e25c;
        puVar14 = (uint *)piVar12[0x16];
        iVar5 = piVar12[0xd];
        piVar12[0x11] = 0;
        puVar14[0x60] = 0;
        *puVar14 = *puVar14 & 0xffffff3f;
        if (iVar5 == 0x3004) {
          if ((puVar14[0x106] == 0) && (-1 < piVar12[0x40] << 0xd)) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0x152,"s3_srvr.c",0x145);
            ssl3_send_alert(piVar12,2,0x28);
            iVar5 = -1;
            piVar12[0xd] = 5;
            goto LAB_0047e268;
          }
          *(int *)(piVar12[0x39] + 0x44) = *(int *)(piVar12[0x39] + 0x44) + 1;
          piVar12[0xd] = 0x2120;
        }
        else {
          iVar5 = (*(code *)PTR_ssl_init_wbio_buffer_006a8010)(piVar12,1);
          if (iVar5 == 0) goto LAB_0047e25c;
          ssl3_init_finished_mac(piVar12);
          piVar12[0xd] = 0x2110;
          puVar14 = (uint *)piVar12[0x16];
          *(int *)(piVar12[0x39] + 0x40) = *(int *)(piVar12[0x39] + 0x40) + 1;
        }
        goto LAB_0047e0fc;
      }
      uVar9 = 0x10c;
LAB_0047ee4c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0x44,"s3_srvr.c",uVar9);
      goto LAB_0047ecb4;
    }
    if (0x220f < iVar16) {
      puVar14 = (uint *)piVar12[0x16];
      if (puVar14[0x60] == 0) {
        *puVar14 = *puVar14 | 0x80;
      }
      iVar5 = ssl3_get_next_proto(piVar12);
      if (iVar5 < 1) goto LAB_0047e268;
      puVar14 = (uint *)piVar12[0x16];
      piVar12[0x11] = 0;
      piVar12[0xd] = 0x21c0;
      goto LAB_0047e0fc;
    }
    if (iVar16 < 0x21f0) goto LAB_0047e938;
    if (iVar16 < 0x21f2) {
      iVar5 = ssl3_send_newsession_ticket(piVar12);
      if (iVar5 < 1) goto LAB_0047e268;
      puVar14 = (uint *)piVar12[0x16];
      piVar12[0x11] = 0;
      piVar12[0xd] = 0x21d0;
      goto LAB_0047e0fc;
    }
    if (1 < iVar16 - 0x2200U) goto LAB_0047e938;
    iVar5 = ssl3_send_cert_status(piVar12);
    if (iVar5 < 1) goto LAB_0047e268;
    piVar12[0x11] = 0;
    piVar12[0xd] = 0x2150;
    uVar7 = *(uint *)(piVar12[0x16] + 0x354);
    goto joined_r0x0047e100;
  }
  if (iVar16 < 0x21e0) {
    if (iVar16 < 0x21a2) {
      if (iVar16 < 0x21a0) {
        if (1 < iVar16 - 0x2190U) goto LAB_0047e938;
        iVar5 = ssl3_get_client_key_exchange(piVar12);
        if (iVar5 < 1) goto LAB_0047e268;
        if (iVar5 != 2) {
          if ((*piVar12 >> 8 != 3) || (*piVar12 < 0x303)) {
            puVar14 = (uint *)piVar12[0x16];
            piVar12[0x11] = 0;
            piVar12[0xd] = 0x21a0;
            if (puVar14[0x5e] != 0) {
              iVar5 = ssl3_digest_cached_records(piVar12);
              if (iVar5 == 0) goto LAB_0047ecb4;
              puVar14 = (uint *)piVar12[0x16];
            }
            iVar5 = 0;
            iStack_80 = 0;
            do {
              if (*(int *)(puVar14[0x5f] + iVar5) != 0) {
                pcVar8 = *(code **)(*(int *)(piVar12[2] + 100) + 0x1c);
                uVar9 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
                uVar9 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar9);
                (*pcVar8)(piVar12,uVar9,piVar12[0x16] + iStack_80 + 0x1b4);
                uVar9 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)
                                  (*(undefined4 *)(*(int *)(piVar12[0x16] + 0x17c) + iVar5));
                iVar10 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar9);
                if (iVar10 < 0) goto LAB_0047e25c;
                puVar14 = (uint *)piVar12[0x16];
                iStack_80 = iStack_80 + iVar10;
              }
              iVar5 = iVar5 + 4;
            } while (iVar5 != 0x18);
            goto LAB_0047e0fc;
          }
          piVar12[0x11] = 0;
          piVar12[0xd] = 0x21a0;
          if (*(int *)(piVar12[0x30] + 0x9c) != 0) {
            puVar14 = (uint *)piVar12[0x16];
            if (puVar14[0x5e] == 0) {
              uVar9 = 0x280;
              goto LAB_0047ee4c;
            }
            *puVar14 = *puVar14 | 0x20;
            iVar5 = ssl3_digest_cached_records(piVar12);
            if (iVar5 != 0) goto LAB_0047e4cc;
            goto LAB_0047ecb4;
          }
          goto LAB_0047e4cc;
        }
      }
      else {
        iVar5 = ssl3_get_cert_verify(piVar12);
        if (iVar5 < 1) goto LAB_0047e268;
      }
      puVar14 = (uint *)piVar12[0x16];
      iVar5 = 0x2210;
      uVar7 = puVar14[0x107];
      piVar12[0x11] = 0;
      if (uVar7 == 0) {
        iVar5 = 0x21c0;
      }
      piVar12[0xd] = iVar5;
    }
    else {
      if (iVar16 < 0x21c0) goto LAB_0047e938;
      if (iVar16 < 0x21c2) {
        puVar14 = (uint *)piVar12[0x16];
        if (puVar14[0x60] == 0) {
          *puVar14 = *puVar14 | 0x80;
        }
        iVar5 = ssl3_get_finished(piVar12,0x21c0,0x21c1);
        if (iVar5 < 1) goto LAB_0047e268;
        if (piVar12[0x1b] == 0) {
LAB_0047e914:
          if (piVar12[0x50] == 0) {
            puVar14 = (uint *)piVar12[0x16];
            piVar12[0x11] = 0;
            piVar12[0xd] = 0x21d0;
          }
          else {
            puVar14 = (uint *)piVar12[0x16];
            piVar12[0x11] = 0;
            piVar12[0xd] = 0x21f0;
          }
        }
        else {
          puVar14 = (uint *)piVar12[0x16];
          piVar12[0xd] = 3;
          piVar12[0x11] = 0;
        }
      }
      else {
        if (1 < iVar16 - 0x21d0U) goto LAB_0047e938;
        pcVar8 = *(code **)(*(int *)(piVar12[2] + 100) + 8);
        *(undefined4 *)(piVar12[0x30] + 0xb4) = *(undefined4 *)(piVar12[0x16] + 0x344);
        iVar5 = (*pcVar8)(piVar12);
        if (iVar5 == 0) goto LAB_0047e25c;
        iVar5 = ssl3_send_change_cipher_spec(piVar12,0x21d0,0x21d1);
        if (iVar5 < 1) goto LAB_0047e268;
        piVar12[0x11] = 0;
        piVar12[0xd] = 0x21e0;
        iVar5 = (**(code **)(*(int *)(piVar12[2] + 100) + 0x10))(piVar12,0x22);
        if (iVar5 == 0) goto LAB_0047e25c;
LAB_0047e4cc:
        puVar14 = (uint *)piVar12[0x16];
      }
    }
  }
  else {
    iVar5 = ssl3_send_finished(piVar12,0x21e0,0x21e1,
                               *(undefined4 *)(*(int *)(piVar12[2] + 100) + 0x28),
                               *(undefined4 *)(*(int *)(piVar12[2] + 100) + 0x2c));
    if (iVar5 < 1) goto LAB_0047e268;
    puVar14 = (uint *)piVar12[0x16];
    piVar12[0xd] = 0x2100;
    if (piVar12[0x1b] == 0) {
      puVar14[0xd4] = 3;
      piVar12[0x11] = 0;
    }
    else if (puVar14[0x107] == 0) {
      puVar14[0xd4] = 0x21c0;
      piVar12[0x11] = 0;
    }
    else {
      puVar14[0xd4] = 0x2210;
      piVar12[0x11] = 0;
    }
  }
LAB_0047e0fc:
  uVar7 = puVar14[0xd5];
joined_r0x0047e100:
  if (uVar7 == 0) {
LAB_0047e348:
    if ((piVar12[0x3a] != 0) &&
       (iVar5 = (*(code *)PTR_BIO_ctrl_006a6e18)(piVar12[4],0xb,0,0), iVar5 < 1)) {
      iVar16 = piVar12[7];
      while( true ) {
        piVar12[7] = iVar16 + -1;
        if (pcVar15 != (code *)0x0) {
LAB_0047e278:
          (*pcVar15)(piVar12,0x2002,iVar5);
        }
LAB_0047e298:
        if (iStack_6c == *(int *)puVar4) break;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047ec04:
        ssl3_send_alert(piVar12,2,iStack_70);
        if (iStack_70 != 0x73) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xe2,"s3_srvr.c",0x181);
        }
LAB_0047e25c:
        iVar5 = -1;
        piVar12[0xd] = 5;
LAB_0047e268:
        iVar16 = piVar12[7];
      }
      return iVar5;
    }
    if (pcVar15 != (code *)0x0) {
      iVar5 = piVar12[0xd];
      if (iVar5 != iVar16) {
        piVar12[0xd] = iVar16;
        (*pcVar15)(piVar12,0x2001,1);
        bVar2 = iVar5 < 0x2182;
        piVar12[0xd] = iVar5;
        iVar16 = iVar5;
      }
      goto LAB_0047e070;
    }
  }
LAB_0047e108:
  iVar16 = piVar12[0xd];
  bVar2 = iVar16 < 0x2182;
  goto LAB_0047e110;
}

