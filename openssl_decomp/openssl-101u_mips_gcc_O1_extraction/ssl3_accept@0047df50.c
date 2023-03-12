
int ssl3_accept(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  int iVar9;
  undefined *puVar10;
  int iVar11;
  uint *puVar12;
  code *pcVar13;
  int iVar14;
  int local_40;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_34 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&local_34,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  pcVar13 = (code *)param_1[0x34];
  *puVar4 = 0;
  puVar10 = PTR_SSL_state_006a7808;
  if (pcVar13 == (code *)0x0) {
    pcVar13 = *(code **)(param_1[0x39] + 0x9c);
  }
  param_1[7] = param_1[7] + 1;
  uVar5 = (*(code *)puVar10)(param_1);
  if (((uVar5 & 0x3000) == 0) ||
     (uVar5 = (*(code *)PTR_SSL_state_006a7808)(param_1), (uVar5 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a77e8)(param_1);
  }
  if (param_1[0x26] == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xb3,"s3_srvr.c",0xeb);
    iVar6 = -1;
    goto LAB_0047e298;
  }
  if (param_1[0x62] != 0) {
    param_1[0x62] = 0;
    param_1[99] = param_1[99] + 1;
  }
  bVar1 = param_1[0xd] < 0x2182;
  iVar14 = param_1[0xd];
LAB_0047e070:
  if (!bVar1) goto LAB_0047e11c;
LAB_0047e07c:
  puVar10 = PTR_BIO_ctrl_006a6e18;
  if (0x217f < iVar14) {
    iVar6 = ssl3_check_client_hello(param_1);
    if (iVar6 < 1) goto LAB_0047e268;
    puVar12 = (uint *)param_1[0x16];
    if (iVar6 == 2) {
      param_1[0xd] = 0x2112;
      goto LAB_0047e0fc;
    }
    if (puVar12[0xe4] != 0) {
      iVar6 = ssl3_get_client_certificate(param_1);
      if (iVar6 < 1) goto LAB_0047e268;
      puVar12 = (uint *)param_1[0x16];
    }
    param_1[0x11] = 0;
    param_1[0xd] = 0x2190;
    goto LAB_0047e0fc;
  }
  if (iVar14 < 0x2132) {
    if (0x212f < iVar14) {
      iVar6 = ssl3_send_server_hello(param_1);
      if (iVar6 < 1) goto LAB_0047e268;
      if (param_1[0x1b] != 0) goto LAB_0047e914;
      puVar12 = (uint *)param_1[0x16];
      param_1[0x11] = 0;
      param_1[0xd] = 0x2140;
      goto LAB_0047e0fc;
    }
    if (iVar14 < 0x2113) {
      if (0x210f < iVar14) {
        param_1[0xc] = 0;
        if ((param_1[6] != 4) && (iVar6 = ssl3_get_client_hello(param_1), iVar6 < 1))
        goto LAB_0047e268;
        puVar12 = (uint *)param_1[0x16];
        local_30 = 0x70;
        if (((*(uint *)(puVar12[0xd1] + 0xc) & 0x400) != 0) && (param_1[0x66] != 0)) {
          if (param_1[0x69] == 0) {
            local_30 = 0x73;
            goto LAB_0047ec04;
          }
          iVar6 = (*(code *)PTR_SSL_srp_server_param_with_username_006a8028)(param_1,&local_30);
          if (iVar6 < 0) {
            param_1[6] = 4;
            goto LAB_0047e268;
          }
          if (iVar6 != 0) goto LAB_0047ec04;
          puVar12 = (uint *)param_1[0x16];
        }
        param_1[0x11] = 0;
        param_1[100] = 2;
        param_1[0xd] = 0x2130;
        goto LAB_0047e0fc;
      }
      if (iVar14 == 0x2000) goto LAB_0047e5b8;
      if (iVar14 < 0x2001) {
        if (iVar14 == 3) {
          ssl3_cleanup_key_block(param_1);
          (*(code *)PTR_BUF_MEM_free_006a7494)(param_1[0xf]);
          puVar10 = PTR_ssl_free_wbio_buffer_006a801c;
          param_1[0xf] = 0;
          (*(code *)puVar10)(param_1);
          param_1[0x11] = 0;
          puVar10 = PTR_ssl_update_cache_006a802c;
          if (param_1[100] != 2) {
            iVar6 = 1;
            goto LAB_0047e268;
          }
          param_1[100] = 0;
          param_1[10] = 0;
          (*(code *)puVar10)(param_1,2);
          *(int *)(param_1[0x39] + 0x48) = *(int *)(param_1[0x39] + 0x48) + 1;
          param_1[8] = (int)ssl3_accept;
          if (pcVar13 != (code *)0x0) {
            (*pcVar13)(param_1,0x20,1);
            iVar6 = 1;
            param_1[7] = param_1[7] + -1;
            goto LAB_0047e278;
          }
          iVar6 = 1;
          param_1[7] = param_1[7] + -1;
          goto LAB_0047e298;
        }
      }
      else {
        if (iVar14 == 0x2003) goto LAB_0047e5b8;
        if (iVar14 == 0x2100) {
          param_1[6] = 2;
          iVar6 = (*(code *)puVar10)(param_1[4],0xb,0,0);
          if (iVar6 < 1) {
            iVar6 = -1;
            goto LAB_0047e268;
          }
          puVar12 = (uint *)param_1[0x16];
          param_1[6] = 1;
          param_1[0xd] = puVar12[0xd4];
          goto LAB_0047e0fc;
        }
      }
    }
    else if (0x211f < iVar14) {
      if (iVar14 < 0x2122) {
        param_1[0xc] = 0;
        if (iVar14 == 0x2120) {
          puVar10 = *(undefined **)(param_1[0xf] + 4);
          *puVar10 = 0;
          puVar10[1] = 0;
          puVar10[2] = 0;
          puVar10[3] = 0;
          param_1[0x12] = 0;
          param_1[0xd] = 0x2121;
          param_1[0x11] = 4;
        }
        iVar6 = ssl3_do_write(param_1,0x16);
        if (iVar6 < 1) goto LAB_0047e268;
        *(undefined4 *)(param_1[0x16] + 0x350) = 0x2122;
        param_1[0x11] = 0;
        param_1[0xd] = 0x2100;
        ssl3_init_finished_mac(param_1);
        puVar12 = (uint *)param_1[0x16];
        goto LAB_0047e0fc;
      }
      if (iVar14 == 0x2122) {
        puVar12 = (uint *)param_1[0x16];
        param_1[0xd] = 3;
        goto LAB_0047e0fc;
      }
    }
    goto LAB_0047e938;
  }
  if (0x2151 < iVar14) {
    if (iVar14 < 0x2160) goto LAB_0047e938;
    if (iVar14 < 0x2162) {
      uVar5 = param_1[0x32];
      if (((uVar5 & 1) == 0) || ((*(int *)(param_1[0x30] + 0x9c) != 0 && ((uVar5 & 4) != 0)))) {
        iVar6 = param_1[0x16];
      }
      else {
        iVar6 = param_1[0x16];
        iVar9 = *(int *)(iVar6 + 0x344);
        if (((((*(uint *)(iVar9 + 0x10) & 4) == 0) || ((uVar5 & 2) != 0)) &&
            ((*(uint *)(iVar9 + 0x10) & 0x420) == 0)) && ((*(uint *)(iVar9 + 0xc) & 0x100) == 0)) {
          *(undefined4 *)(iVar6 + 0x390) = 1;
          iVar6 = ssl3_send_certificate_request(param_1);
          if (iVar6 < 1) goto LAB_0047e268;
          puVar12 = (uint *)param_1[0x16];
          param_1[0xd] = 0x2100;
          puVar12[0xd4] = 0x2180;
          param_1[0x11] = 0;
          goto LAB_0047e0fc;
        }
      }
      iVar14 = *(int *)(iVar6 + 0x178);
      *(undefined4 *)(iVar6 + 0x390) = 0;
      param_1[0xd] = 0x2170;
      if (iVar14 != 0) {
        iVar6 = ssl3_digest_cached_records(param_1);
        if (iVar6 == 0) {
LAB_0047ecb4:
          iVar6 = -1;
          param_1[0xd] = 5;
          goto LAB_0047e298;
        }
        iVar14 = param_1[0xd];
        bVar1 = iVar14 < 0x2182;
        goto LAB_0047e110;
      }
      iVar14 = 0x2170;
      bVar1 = true;
    }
    if (iVar14 - 0x2170U < 2) {
      if (iVar14 == 0x2170) {
        puVar10 = *(undefined **)(param_1[0xf] + 4);
        *puVar10 = 0xe;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10[3] = 0;
        param_1[0x12] = 0;
        param_1[0xd] = 0x2171;
        param_1[0x11] = 4;
      }
      iVar6 = ssl3_do_write(param_1,0x16);
      if (iVar6 < 1) goto LAB_0047e268;
      puVar12 = (uint *)param_1[0x16];
      puVar12[0xd4] = 0x2180;
      param_1[0x11] = 0;
      param_1[0xd] = 0x2100;
      goto LAB_0047e0fc;
    }
LAB_0047e938:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xff,"s3_srvr.c",0x364);
    iVar6 = -1;
    goto LAB_0047e268;
  }
  if (iVar14 < 0x2150) {
    if (1 < iVar14 - 0x2140U) goto LAB_0047e938;
    iVar6 = param_1[0x16];
    if (((*(uint *)(*(int *)(iVar6 + 0x344) + 0x10) & 0x424) == 0) &&
       ((*(uint *)(*(int *)(iVar6 + 0x344) + 0xc) & 0x100) == 0)) {
      if (iVar14 == 0x2140) {
        iVar6 = (*(code *)PTR_ssl_get_server_send_cert_006a7ff0)(param_1);
        if ((iVar6 == 0) &&
           ((*(int *)(*(int *)(param_1[0x16] + 0x344) + 0x10) != 0x20 ||
            ((*(uint *)(*(int *)(param_1[0x16] + 0x344) + 0xc) & 0x10) != 0)))) {
          uVar8 = 0xd1b;
LAB_0047eeb4:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9a,0x44,"s3_srvr.c",uVar8);
          param_1[0xd] = 5;
          iVar6 = 0;
          goto LAB_0047e268;
        }
        iVar6 = ssl3_output_cert_chain(param_1,iVar6);
        if (iVar6 == 0) {
          uVar8 = 0xd23;
          goto LAB_0047eeb4;
        }
        param_1[0x11] = iVar6;
        param_1[0x12] = 0;
        param_1[0xd] = 0x2141;
      }
      iVar6 = ssl3_do_write(param_1,0x16);
      if (iVar6 < 1) goto LAB_0047e268;
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
  }
  else {
    iVar6 = param_1[0x16];
    uVar5 = *(uint *)(*(int *)(iVar6 + 0x344) + 0xc);
    *(undefined4 *)(iVar6 + 0x370) = 0;
    if ((((uVar5 & 0x100) == 0) || (*(int *)(param_1[0x39] + 0x14c) == 0)) && ((uVar5 & 0x48e) == 0)
       ) {
      bVar2 = true;
      if ((uVar5 & 1) != 0) {
        if (*(int *)(param_1[0x26] + 0x34) == 0) goto LAB_0047e9bc;
        bVar2 = true;
        if ((*(uint *)(*(int *)(iVar6 + 0x344) + 0x20) & 2) != 0) {
          iVar9 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
          iVar6 = param_1[0x16];
          iVar11 = 0x200;
          if ((*(uint *)(*(int *)(iVar6 + 0x344) + 0x20) & 8) == 0) {
            iVar11 = 0x400;
          }
          if (iVar11 < iVar9 << 3) goto LAB_0047e9bc;
          bVar2 = true;
        }
      }
    }
    else {
LAB_0047e9bc:
      iVar6 = ssl3_send_server_key_exchange(param_1);
      if (iVar6 < 1) goto LAB_0047e268;
      iVar6 = param_1[0x16];
      bVar2 = false;
    }
    param_1[0x11] = 0;
    param_1[0xd] = 0x2160;
  }
  if (*(int *)(iVar6 + 0x354) != 0) goto LAB_0047e108;
  if (!bVar2) goto LAB_0047e348;
  iVar14 = param_1[0xd];
  bVar1 = iVar14 < 0x2182;
LAB_0047e110:
  if (bVar1) goto LAB_0047e07c;
LAB_0047e11c:
  if (0x21e1 < iVar14) {
    if (0x2211 < iVar14) {
      if ((iVar14 != 0x4000) && (iVar14 != 0x6000)) {
        if (iVar14 != 0x3004) goto LAB_0047e938;
        param_1[100] = 1;
      }
LAB_0047e5b8:
      param_1[9] = 1;
      if (pcVar13 != (code *)0x0) {
        (*pcVar13)(param_1,0x10,1);
      }
      if (*param_1 >> 8 == 3) {
        param_1[1] = 0x2000;
        if (param_1[0xf] == 0) {
          iVar6 = (*(code *)PTR_BUF_MEM_new_006a749c)();
          if (iVar6 == 0) goto LAB_0047e25c;
          iVar9 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(iVar6,0x4000);
          if (iVar9 == 0) {
            (*(code *)PTR_BUF_MEM_free_006a7494)(iVar6);
            goto LAB_0047e25c;
          }
          param_1[0xf] = iVar6;
        }
        iVar6 = ssl3_setup_buffers(param_1);
        if (iVar6 == 0) goto LAB_0047e25c;
        puVar12 = (uint *)param_1[0x16];
        iVar6 = param_1[0xd];
        param_1[0x11] = 0;
        puVar12[0x60] = 0;
        *puVar12 = *puVar12 & 0xffffff3f;
        if (iVar6 == 0x3004) {
          if ((puVar12[0x106] == 0) && (-1 < param_1[0x40] << 0xd)) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0x152,"s3_srvr.c",0x145);
            ssl3_send_alert(param_1,2,0x28);
            iVar6 = -1;
            param_1[0xd] = 5;
            goto LAB_0047e268;
          }
          *(int *)(param_1[0x39] + 0x44) = *(int *)(param_1[0x39] + 0x44) + 1;
          param_1[0xd] = 0x2120;
        }
        else {
          iVar6 = (*(code *)PTR_ssl_init_wbio_buffer_006a8010)(param_1,1);
          if (iVar6 == 0) goto LAB_0047e25c;
          ssl3_init_finished_mac(param_1);
          param_1[0xd] = 0x2110;
          puVar12 = (uint *)param_1[0x16];
          *(int *)(param_1[0x39] + 0x40) = *(int *)(param_1[0x39] + 0x40) + 1;
        }
        goto LAB_0047e0fc;
      }
      uVar8 = 0x10c;
LAB_0047ee4c:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0x44,"s3_srvr.c",uVar8);
      goto LAB_0047ecb4;
    }
    if (0x220f < iVar14) {
      puVar12 = (uint *)param_1[0x16];
      if (puVar12[0x60] == 0) {
        *puVar12 = *puVar12 | 0x80;
      }
      iVar6 = ssl3_get_next_proto(param_1);
      if (iVar6 < 1) goto LAB_0047e268;
      puVar12 = (uint *)param_1[0x16];
      param_1[0x11] = 0;
      param_1[0xd] = 0x21c0;
      goto LAB_0047e0fc;
    }
    if (iVar14 < 0x21f0) goto LAB_0047e938;
    if (iVar14 < 0x21f2) {
      iVar6 = ssl3_send_newsession_ticket(param_1);
      if (iVar6 < 1) goto LAB_0047e268;
      puVar12 = (uint *)param_1[0x16];
      param_1[0x11] = 0;
      param_1[0xd] = 0x21d0;
      goto LAB_0047e0fc;
    }
    if (1 < iVar14 - 0x2200U) goto LAB_0047e938;
    iVar6 = ssl3_send_cert_status(param_1);
    if (iVar6 < 1) goto LAB_0047e268;
    param_1[0x11] = 0;
    param_1[0xd] = 0x2150;
    uVar5 = *(uint *)(param_1[0x16] + 0x354);
    goto joined_r0x0047e100;
  }
  if (iVar14 < 0x21e0) {
    if (iVar14 < 0x21a2) {
      if (iVar14 < 0x21a0) {
        if (1 < iVar14 - 0x2190U) goto LAB_0047e938;
        iVar6 = ssl3_get_client_key_exchange(param_1);
        if (iVar6 < 1) goto LAB_0047e268;
        if (iVar6 != 2) {
          if ((*param_1 >> 8 != 3) || (*param_1 < 0x303)) {
            puVar12 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x21a0;
            if (puVar12[0x5e] != 0) {
              iVar6 = ssl3_digest_cached_records(param_1);
              if (iVar6 == 0) goto LAB_0047ecb4;
              puVar12 = (uint *)param_1[0x16];
            }
            iVar6 = 0;
            local_40 = 0;
            do {
              if (*(int *)(puVar12[0x5f] + iVar6) != 0) {
                pcVar7 = *(code **)(*(int *)(param_1[2] + 100) + 0x1c);
                uVar8 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
                uVar8 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar8);
                (*pcVar7)(param_1,uVar8,param_1[0x16] + local_40 + 0x1b4);
                uVar8 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)
                                  (*(undefined4 *)(*(int *)(param_1[0x16] + 0x17c) + iVar6));
                iVar9 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar8);
                if (iVar9 < 0) goto LAB_0047e25c;
                puVar12 = (uint *)param_1[0x16];
                local_40 = local_40 + iVar9;
              }
              iVar6 = iVar6 + 4;
            } while (iVar6 != 0x18);
            goto LAB_0047e0fc;
          }
          param_1[0x11] = 0;
          param_1[0xd] = 0x21a0;
          if (*(int *)(param_1[0x30] + 0x9c) != 0) {
            puVar12 = (uint *)param_1[0x16];
            if (puVar12[0x5e] == 0) {
              uVar8 = 0x280;
              goto LAB_0047ee4c;
            }
            *puVar12 = *puVar12 | 0x20;
            iVar6 = ssl3_digest_cached_records(param_1);
            if (iVar6 != 0) goto LAB_0047e4cc;
            goto LAB_0047ecb4;
          }
          goto LAB_0047e4cc;
        }
      }
      else {
        iVar6 = ssl3_get_cert_verify(param_1);
        if (iVar6 < 1) goto LAB_0047e268;
      }
      puVar12 = (uint *)param_1[0x16];
      iVar6 = 0x2210;
      uVar5 = puVar12[0x107];
      param_1[0x11] = 0;
      if (uVar5 == 0) {
        iVar6 = 0x21c0;
      }
      param_1[0xd] = iVar6;
    }
    else {
      if (iVar14 < 0x21c0) goto LAB_0047e938;
      if (iVar14 < 0x21c2) {
        puVar12 = (uint *)param_1[0x16];
        if (puVar12[0x60] == 0) {
          *puVar12 = *puVar12 | 0x80;
        }
        iVar6 = ssl3_get_finished(param_1,0x21c0,0x21c1);
        if (iVar6 < 1) goto LAB_0047e268;
        if (param_1[0x1b] == 0) {
LAB_0047e914:
          if (param_1[0x50] == 0) {
            puVar12 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x21d0;
          }
          else {
            puVar12 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x21f0;
          }
        }
        else {
          puVar12 = (uint *)param_1[0x16];
          param_1[0xd] = 3;
          param_1[0x11] = 0;
        }
      }
      else {
        if (1 < iVar14 - 0x21d0U) goto LAB_0047e938;
        pcVar7 = *(code **)(*(int *)(param_1[2] + 100) + 8);
        *(undefined4 *)(param_1[0x30] + 0xb4) = *(undefined4 *)(param_1[0x16] + 0x344);
        iVar6 = (*pcVar7)(param_1);
        if (iVar6 == 0) goto LAB_0047e25c;
        iVar6 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
        if (iVar6 < 1) goto LAB_0047e268;
        param_1[0x11] = 0;
        param_1[0xd] = 0x21e0;
        iVar6 = (**(code **)(*(int *)(param_1[2] + 100) + 0x10))(param_1,0x22);
        if (iVar6 == 0) goto LAB_0047e25c;
LAB_0047e4cc:
        puVar12 = (uint *)param_1[0x16];
      }
    }
  }
  else {
    iVar6 = ssl3_send_finished(param_1,0x21e0,0x21e1,
                               *(undefined4 *)(*(int *)(param_1[2] + 100) + 0x28),
                               *(undefined4 *)(*(int *)(param_1[2] + 100) + 0x2c));
    if (iVar6 < 1) goto LAB_0047e268;
    puVar12 = (uint *)param_1[0x16];
    param_1[0xd] = 0x2100;
    if (param_1[0x1b] == 0) {
      puVar12[0xd4] = 3;
      param_1[0x11] = 0;
    }
    else if (puVar12[0x107] == 0) {
      puVar12[0xd4] = 0x21c0;
      param_1[0x11] = 0;
    }
    else {
      puVar12[0xd4] = 0x2210;
      param_1[0x11] = 0;
    }
  }
LAB_0047e0fc:
  uVar5 = puVar12[0xd5];
joined_r0x0047e100:
  if (uVar5 == 0) {
LAB_0047e348:
    if ((param_1[0x3a] != 0) &&
       (iVar6 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_1[4],0xb,0,0), iVar6 < 1)) {
      iVar14 = param_1[7];
      while( true ) {
        param_1[7] = iVar14 + -1;
        if (pcVar13 != (code *)0x0) {
LAB_0047e278:
          (*pcVar13)(param_1,0x2002,iVar6);
        }
LAB_0047e298:
        if (local_2c == *(int *)puVar3) break;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0047ec04:
        ssl3_send_alert(param_1,2,local_30);
        if (local_30 != 0x73) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x80,0xe2,"s3_srvr.c",0x181);
        }
LAB_0047e25c:
        iVar6 = -1;
        param_1[0xd] = 5;
LAB_0047e268:
        iVar14 = param_1[7];
      }
      return iVar6;
    }
    if (pcVar13 != (code *)0x0) {
      iVar6 = param_1[0xd];
      if (iVar6 != iVar14) {
        param_1[0xd] = iVar14;
        (*pcVar13)(param_1,0x2001,1);
        bVar1 = iVar6 < 0x2182;
        param_1[0xd] = iVar6;
        iVar14 = iVar6;
      }
      goto LAB_0047e070;
    }
  }
LAB_0047e108:
  iVar14 = param_1[0xd];
  bVar1 = iVar14 < 0x2182;
  goto LAB_0047e110;
}

