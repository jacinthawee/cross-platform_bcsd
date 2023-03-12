
int ssl3_connect(uint *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  code *pcVar10;
  undefined *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puVar11 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_34,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  pcVar10 = (code *)param_1[0x34];
  *puVar2 = 0;
  puVar1 = PTR_SSL_state_006a88f4;
  if (pcVar10 == (code *)0x0) {
    pcVar10 = *(code **)(param_1[0x39] + 0x9c);
  }
  param_1[7] = param_1[7] + 1;
  uVar3 = (*(code *)puVar1)(param_1);
  if (((uVar3 & 0x3000) == 0) ||
     (uVar3 = (*(code *)PTR_SSL_state_006a88f4)(param_1), (uVar3 & 0x4000) != 0)) {
    (*(code *)PTR_SSL_clear_006a88d4)(param_1);
  }
  if (param_1[0x62] != 0) {
    param_1[0x62] = 0;
    param_1[99] = param_1[99] + 1;
  }
  uVar3 = param_1[0xd];
LAB_00488468:
  uVar13 = uVar3;
  if (0x1181 < (int)uVar3) goto LAB_0048851c;
LAB_00488478:
  puVar1 = PTR_BIO_ctrl_006a7f18;
  if ((int)uVar13 < 0x1180) {
    if ((int)uVar13 < 0x1132) {
      if ((int)uVar13 < 0x1130) {
        if (uVar13 != 0x1100) {
          if ((int)uVar13 < 0x1101) {
            if (uVar13 == 0x1000) goto LAB_0048886c;
            if (uVar13 == 0x1003) goto LAB_0048886c;
            if (uVar13 == 3) {
              ssl3_cleanup_key_block(param_1);
              if (param_1[0xf] != 0) {
                (*(code *)PTR_BUF_MEM_free_006a8594)();
                param_1[0xf] = 0;
              }
              if ((*(uint *)param_1[0x16] & 4) == 0) {
                (*(code *)PTR_ssl_free_wbio_buffer_006a9024)(param_1);
              }
              puVar1 = PTR_ssl_update_cache_006a9028;
              param_1[0x11] = 0;
              param_1[100] = 0;
              param_1[10] = 0;
              (*(code *)puVar1)(param_1,1);
              if (param_1[0x1b] == 0) {
                iVar4 = *(int *)(param_1[0x39] + 0x3c);
                param_1[8] = (uint)ssl3_connect;
                *(int *)(param_1[0x39] + 0x3c) = iVar4 + 1;
              }
              else {
                uVar3 = param_1[0x39];
                *(int *)(uVar3 + 0x58) = *(int *)(uVar3 + 0x58) + 1;
                iVar4 = *(int *)(uVar3 + 0x3c);
                param_1[8] = (uint)ssl3_connect;
                *(int *)(uVar3 + 0x3c) = iVar4 + 1;
              }
              if (pcVar10 == (code *)0x0) {
                iVar4 = 1;
                param_1[7] = param_1[7] - 1;
                goto LAB_00488698;
              }
              (*pcVar10)(param_1,0x20,1);
              iVar4 = 1;
              goto LAB_0048868c;
            }
          }
          else if (0x110f < (int)uVar13) {
            if ((int)uVar13 < 0x1112) {
              param_1[0xc] = 0;
              iVar4 = ssl3_client_hello(param_1);
              if (0 < iVar4) {
                param_1[0x11] = 0;
                param_1[0xd] = 0x1120;
                if (param_1[5] != param_1[4]) {
                  uVar3 = (*(code *)PTR_BIO_push_006a85c0)();
                  puVar6 = (uint *)param_1[0x16];
                  param_1[4] = uVar3;
                  goto LAB_00488900;
                }
                goto LAB_00488744;
              }
            }
            else {
              if (1 < uVar13 - 0x1120) goto LAB_00488a84;
              iVar4 = ssl3_get_server_hello(param_1);
              if (0 < iVar4) {
                if (param_1[0x1b] == 0) {
                  uVar3 = param_1[0x16];
                  param_1[0x11] = 0;
                  param_1[0xd] = 0x1130;
                }
                else {
                  param_1[0xd] = 0x11d0;
                  if (param_1[0x50] != 0) {
                    param_1[0xd] = 0x11e0;
                  }
                  uVar3 = param_1[0x16];
                  param_1[0x11] = 0;
                }
                if (*(int *)(uVar3 + 0x354) != 0) goto LAB_00488508;
                goto LAB_0048857c;
              }
            }
            goto LAB_0048868c;
          }
          goto LAB_00488a84;
        }
        param_1[6] = 2;
        iVar4 = (*(code *)puVar1)(param_1[4],0xb,0,0);
        if (0 < iVar4) {
          puVar6 = (uint *)param_1[0x16];
          param_1[6] = 1;
          param_1[0xd] = puVar6[0xd4];
          goto LAB_00488900;
        }
        goto LAB_00488aa8;
      }
      if (*(int *)(param_1[0x30] + 0xe4) == 0) {
        puVar6 = (uint *)param_1[0x16];
        iVar4 = 1;
      }
      else {
        iVar4 = (**(code **)(param_1[2] + 0x30))
                          (param_1,0x1130,0x1131,0xffffffff,param_1[0x42],&local_30);
        if (local_30 == 0) {
          if (iVar4 < 1) goto LAB_0048868c;
          puVar6 = (uint *)param_1[0x16];
        }
        else {
          puVar6 = (uint *)param_1[0x16];
          puVar6[0xd5] = 1;
          iVar4 = 2;
          if ((puVar6[0xd0] & 0xffffffef) != 4) {
            iVar4 = 1;
          }
        }
      }
      if (iVar4 == 2) {
        uVar3 = 0x11e0;
        param_1[0x11] = 0;
        if (param_1[0x50] == 0) {
          uVar3 = 0x11d0;
        }
        param_1[0x1b] = 1;
        param_1[0xd] = uVar3;
        goto LAB_00488900;
      }
      if (((*(uint *)(puVar6[0xd1] + 0x10) & 4) == 0) &&
         ((*(uint *)(puVar6[0xd1] + 0xc) & 0x100) == 0)) {
        iVar4 = ssl3_get_server_certificate(param_1);
        if (iVar4 < 1) goto LAB_0048868c;
        if (param_1[0x4b] == 0) {
          uVar3 = 0x1140;
          param_1[0xd] = 0x1140;
        }
        else {
          uVar3 = 0x11f0;
          param_1[0xd] = 0x11f0;
        }
        param_1[0x11] = 0;
        if (*(int *)(param_1[0x16] + 0x354) == 0) {
LAB_0048857c:
          if ((param_1[0x3a] == 0) ||
             (iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1[4],0xb,0,0), 0 < iVar4)) {
            if (pcVar10 == (code *)0x0) {
LAB_00488508:
              uVar13 = param_1[0xd];
              do {
                if ((int)uVar13 < 0x1182) goto LAB_00488478;
LAB_0048851c:
                puVar1 = PTR_memcpy_006aabf4;
                if ((int)uVar13 < 0x11e2) {
                  if ((int)uVar13 < 0x11e0) {
                    if ((int)uVar13 < 0x11a2) {
                      if ((int)uVar13 < 0x11a0) goto code_r0x0048853c;
                      iVar4 = ssl3_send_change_cipher_spec(param_1,0x11a0,0x11a1);
                      if (iVar4 < 1) goto LAB_0048868c;
                      uVar3 = param_1[0x16];
                      uVar14 = param_1[0x30];
                      iVar4 = *(int *)(uVar3 + 0x41c);
                      uVar5 = *(undefined4 *)(uVar3 + 0x344);
                      puVar2 = *(undefined4 **)(uVar3 + 0x38c);
                      uVar3 = 0x1200;
                      param_1[0x11] = 0;
                      if (iVar4 == 0) {
                        uVar3 = 0x11b0;
                      }
                      param_1[0xd] = uVar3;
                      *(undefined4 *)(uVar14 + 0xb4) = uVar5;
                      if (puVar2 == (undefined4 *)0x0) {
                        uVar5 = 0;
                      }
                      else {
                        uVar5 = *puVar2;
                      }
                      uVar3 = param_1[2];
                      *(undefined4 *)(uVar14 + 0xb0) = uVar5;
                      iVar4 = (**(code **)(*(int *)(uVar3 + 100) + 8))(param_1);
                      if ((iVar4 == 0) ||
                         (iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0x10))(param_1,0x12),
                         iVar4 == 0)) goto LAB_00488aa8;
                      puVar6 = (uint *)param_1[0x16];
                    }
                    else {
                      if ((int)uVar13 < 0x11b0) goto LAB_00488a84;
                      if ((int)uVar13 < 0x11b2) {
                        iVar4 = ssl3_send_finished(param_1,0x11b0,0x11b1,
                                                   *(undefined4 *)
                                                    (*(int *)(param_1[2] + 100) + 0x20),
                                                   *(undefined4 *)
                                                    (*(int *)(param_1[2] + 100) + 0x24));
                        if (iVar4 < 1) goto LAB_0048868c;
                        puVar6 = (uint *)param_1[0x16];
                        uVar7 = param_1[0x1b];
                        uVar14 = *puVar6;
                        param_1[0xd] = 0x1100;
                        uVar3 = uVar14 & 0xfffffffb;
                        *puVar6 = uVar3;
                        if (uVar7 == 0) {
                          if (param_1[0x50] == 0) {
                            puVar6[0xd4] = 0x11d0;
                            param_1[0x11] = 0;
                          }
                          else {
                            puVar6[0xd4] = 0x11e0;
                            param_1[0x11] = 0;
                          }
                        }
                        else {
                          puVar6[0xd4] = 3;
                          if ((uVar14 & 2) != 0) {
                            param_1[0xd] = 3;
                            puVar6[1] = 0;
                            *puVar6 = uVar3 | 4;
                          }
LAB_00488a00:
                          param_1[0x11] = 0;
                        }
                      }
                      else {
                        if (1 < uVar13 - 0x11d0) goto LAB_00488a84;
                        iVar4 = ssl3_get_finished(param_1,0x11d0,0x11d1);
                        if (iVar4 < 1) goto LAB_0048868c;
                        uVar3 = 0x11a0;
                        puVar6 = (uint *)param_1[0x16];
                        param_1[0x11] = 0;
                        if (param_1[0x1b] == 0) {
                          uVar3 = 3;
                        }
                        param_1[0xd] = uVar3;
                      }
                    }
                  }
                  else {
                    iVar4 = ssl3_get_new_session_ticket(param_1);
                    if (iVar4 < 1) goto LAB_0048868c;
                    puVar6 = (uint *)param_1[0x16];
                    param_1[0x11] = 0;
                    param_1[0xd] = 0x11d0;
                  }
                }
                else if ((int)uVar13 < 0x1202) {
                  if ((int)uVar13 < 0x1200) {
                    if (1 < uVar13 - 0x11f0) goto LAB_00488a84;
                    iVar4 = ssl3_get_cert_status(param_1);
                    if (iVar4 < 1) goto LAB_0048868c;
                    puVar6 = (uint *)param_1[0x16];
                    param_1[0x11] = 0;
                    param_1[0xd] = 0x1140;
                  }
                  else {
                    if (uVar13 == 0x1200) {
                      uVar3 = (uint)*(byte *)(param_1 + 0x5e);
                      puVar9 = *(undefined **)(param_1[0xf] + 4);
                      iVar4 = 0x20 - (uVar3 + 2 & 0x1f);
                      puVar9[4] = *(byte *)(param_1 + 0x5e);
                      (*(code *)puVar1)(puVar9 + 5,param_1[0x5d],uVar3);
                      puVar1 = PTR_memset_006aab00;
                      puVar9[uVar3 + 5] = (char)iVar4;
                      (*(code *)puVar1)(puVar9 + uVar3 + 6,0,iVar4);
                      puVar9[1] = 0;
                      *puVar9 = 0x43;
                      puVar9[3] = (char)iVar4 + (char)(uVar3 + 2);
                      puVar9[2] = (char)(uVar3 + iVar4 + 2 >> 8);
                      param_1[0x11] = uVar3 + iVar4 + 6;
                      param_1[0x12] = 0;
                      param_1[0xd] = 0x1201;
                    }
                    iVar4 = ssl3_do_write(param_1,0x16);
                    if (iVar4 < 1) goto LAB_0048868c;
                    puVar6 = (uint *)param_1[0x16];
                    param_1[0xd] = 0x11b0;
                  }
                }
                else {
                  if ((uVar13 != 0x4000) && (uVar13 != 0x5000)) {
                    if (uVar13 != 0x3004) goto LAB_00488a84;
                    param_1[0xd] = 0x1000;
                    param_1[100] = 1;
                    *(int *)(param_1[0x39] + 0x38) = *(int *)(param_1[0x39] + 0x38) + 1;
                  }
LAB_0048886c:
                  param_1[9] = 0;
                  if (pcVar10 != (code *)0x0) {
                    (*pcVar10)(param_1,0x10,1);
                  }
                  if ((*param_1 & 0xff00) != 0x300) {
                    uVar8 = 0x44;
                    uVar5 = 0xef;
                    goto LAB_00488a94;
                  }
                  param_1[1] = 0x1000;
                  if (param_1[0xf] == 0) {
                    uVar3 = (*(code *)PTR_BUF_MEM_new_006a859c)();
                    if (uVar3 == 0) goto LAB_00488aa8;
                    iVar4 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(uVar3,0x4000);
                    puVar1 = PTR_BUF_MEM_free_006a8594;
                    if (iVar4 == 0) {
                      iVar4 = -1;
                      param_1[7] = param_1[7] - 1;
                      (*(code *)puVar1)(uVar3);
                      goto LAB_00488698;
                    }
                    param_1[0xf] = uVar3;
                  }
                  iVar4 = ssl3_setup_buffers(param_1);
                  if ((iVar4 == 0) ||
                     (iVar4 = (*(code *)PTR_ssl_init_wbio_buffer_006a9048)(param_1,0), iVar4 == 0))
                  goto LAB_00488aa8;
                  ssl3_init_finished_mac(param_1);
                  puVar6 = (uint *)param_1[0x16];
                  param_1[0xd] = 0x1110;
                  *(int *)(param_1[0x39] + 0x34) = *(int *)(param_1[0x39] + 0x34) + 1;
                  param_1[0x11] = 0;
                }
LAB_00488900:
                if (puVar6[0xd5] == 0) goto LAB_0048857c;
                uVar13 = param_1[0xd];
              } while( true );
            }
            uVar14 = param_1[0xd];
            uVar3 = uVar13;
            if (uVar14 != uVar13) {
              param_1[0xd] = uVar13;
              (*pcVar10)(param_1,0x1001,1);
              param_1[0xd] = uVar14;
              uVar3 = uVar14;
            }
            goto LAB_00488468;
          }
          uVar3 = param_1[7];
          goto LAB_00488690;
        }
        goto LAB_00488468;
      }
      param_1[0x11] = 0;
      uVar13 = 0x1140;
      param_1[0xd] = 0x1140;
LAB_00488714:
      iVar4 = ssl3_get_key_exchange(param_1);
      if (0 < iVar4) {
        param_1[0x11] = 0;
        param_1[0xd] = 0x1150;
        iVar4 = ssl3_check_cert_and_algorithm(param_1);
        if (iVar4 != 0) {
LAB_00488744:
          puVar6 = (uint *)param_1[0x16];
          goto LAB_00488900;
        }
        goto LAB_00488aa8;
      }
LAB_0048868c:
      uVar3 = param_1[7];
LAB_00488690:
      param_1[7] = uVar3 - 1;
    }
    else {
      if ((int)uVar13 < 0x1152) {
        if (0x114f < (int)uVar13) {
          iVar4 = ssl3_get_certificate_request(param_1);
          if (0 < iVar4) {
            puVar6 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x1160;
            goto LAB_00488900;
          }
          goto LAB_0048868c;
        }
        if (uVar13 - 0x1140 < 2) goto LAB_00488714;
      }
      else if (0x115f < (int)uVar13) {
        if ((int)uVar13 < 0x1162) {
          iVar4 = (**(code **)(param_1[2] + 0x30))(param_1,0x1160,0x1161,0xe,0x1e,&local_30);
          if (local_30 == 0) {
            if (0 < iVar4) {
              puVar6 = (uint *)param_1[0x16];
              uVar3 = *(uint *)(puVar6[0xd1] + 0xc);
              goto joined_r0x00488dd4;
            }
          }
          else if (iVar4 < 1) {
            puVar6 = (uint *)param_1[0x16];
            uVar3 = *(uint *)(puVar6[0xd1] + 0xc);
joined_r0x00488dd4:
            if ((uVar3 & 0x400) == 0) {
LAB_00488a64:
              uVar14 = puVar6[0xd6];
              uVar3 = 0x1170;
              param_1[0x11] = 0;
              if (uVar14 == 0) {
                uVar3 = 0x1180;
              }
              param_1[0xd] = uVar3;
              goto LAB_00488900;
            }
            iVar4 = (*(code *)PTR_SRP_Calc_A_param_006a91dc)(param_1);
            if (0 < iVar4) {
              puVar6 = (uint *)param_1[0x16];
              goto LAB_00488a64;
            }
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x84,0x169,"s3_clnt.c",0x186);
            ssl3_send_alert(param_1,2,0x50);
          }
          else {
            ssl3_send_alert(param_1,2,0x32);
            iVar4 = -1;
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x91,0x9f,"s3_clnt.c",0x8a0);
          }
          goto LAB_0048868c;
        }
        if (uVar13 - 0x1170 < 4) {
          iVar4 = ssl3_send_client_certificate(param_1);
          if (0 < iVar4) {
            puVar6 = (uint *)param_1[0x16];
            param_1[0x11] = 0;
            param_1[0xd] = 0x1180;
            goto LAB_00488900;
          }
          goto LAB_0048868c;
        }
      }
LAB_00488a84:
      uVar8 = 0xff;
      uVar5 = 0x26a;
LAB_00488a94:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x84,uVar8,"s3_clnt.c",uVar5);
LAB_00488aa8:
      iVar4 = -1;
      param_1[7] = param_1[7] - 1;
    }
LAB_00488698:
    if (pcVar10 != (code *)0x0) {
      (*pcVar10)(param_1,0x1002,iVar4);
    }
    if (local_2c == *(int *)puVar11) {
      return iVar4;
    }
    iVar4 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar1 = PTR_memcpy_006aabf4;
    if (*(int *)(iVar4 + 0x34) != 0x1200) {
      iVar4 = ssl3_do_write(iVar4,0x16);
      return iVar4;
    }
    uVar3 = (uint)*(byte *)(iVar4 + 0x178);
    puVar11 = *(undefined **)(*(int *)(iVar4 + 0x3c) + 4);
    puVar11[4] = *(byte *)(iVar4 + 0x178);
    iVar12 = 0x20 - (uVar3 + 2 & 0x1f);
    (*(code *)puVar1)(puVar11 + 5,*(undefined4 *)(iVar4 + 0x174),uVar3);
    puVar11[uVar3 + 5] = (char)iVar12;
    (*(code *)PTR_memset_006aab00)(puVar11 + uVar3 + 6,0,iVar12);
    puVar11[1] = 0;
    puVar11[3] = (char)iVar12 + (char)(uVar3 + 2);
    *puVar11 = 0x43;
    puVar11[2] = (char)(uVar3 + iVar12 + 2 >> 8);
    *(uint *)(iVar4 + 0x44) = uVar3 + iVar12 + 6;
    *(undefined4 *)(iVar4 + 0x48) = 0;
    *(undefined4 *)(iVar4 + 0x34) = 0x1201;
    iVar4 = ssl3_do_write(iVar4,0x16);
    return iVar4;
  }
  iVar4 = ssl3_send_client_key_exchange(param_1);
  if (0 < iVar4) {
    puVar6 = (uint *)param_1[0x16];
    if (puVar6[0xd6] == 1) {
      param_1[0xd] = 0x1190;
    }
    else {
      param_1[0xd] = 0x11a0;
      puVar6[0x60] = 0;
    }
    if ((*puVar6 & 0x10) == 0) goto LAB_00488a00;
    param_1[0xd] = 0x11a0;
    puVar6[0x60] = 0;
    param_1[0x11] = 0;
    goto LAB_00488900;
  }
  goto LAB_0048868c;
code_r0x0048853c:
  if (1 < uVar13 - 0x1190) goto LAB_00488a84;
  iVar4 = ssl3_send_client_verify(param_1);
  if (iVar4 < 1) goto LAB_0048868c;
  uVar3 = param_1[0x16];
  param_1[0x11] = 0;
  param_1[0xd] = 0x11a0;
  *(undefined4 *)(uVar3 + 0x180) = 0;
  if (*(int *)(uVar3 + 0x354) == 0) goto LAB_0048857c;
  goto LAB_00488508;
}

