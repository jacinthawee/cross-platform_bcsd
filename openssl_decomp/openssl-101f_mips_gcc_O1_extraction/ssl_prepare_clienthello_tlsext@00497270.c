
undefined4 ssl_prepare_clienthello_tlsext(SSL *param_1)

{
  stack_st_SSL_CIPHER *psVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined uVar7;
  code *pcVar8;
  
  psVar1 = SSL_get_ciphers(param_1);
  iVar5 = 0;
  do {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
    if (iVar2 <= iVar5) {
      return 1;
    }
    iVar2 = (*(code *)PTR_sk_value_006a7f24)(psVar1,iVar5);
  } while (((*(uint *)(iVar2 + 0xc) & 0xe0) == 0) &&
          (iVar5 = iVar5 + 1, (*(uint *)(iVar2 + 0x10) & 0x40) == 0));
  uVar3 = 1;
  if (0x300 < param_1->version) {
    if (param_1->tlsext_ecpointformatlist_length != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar4 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(3,"t1_lib.c",0x6e0);
    param_1->tlsext_ecpointformatlist_length = (size_t)puVar4;
    if (puVar4 == (undefined *)0x0) {
      uVar3 = 0x6e2;
      pcVar8 = (code *)PTR_ERR_put_error_006a9030;
    }
    else {
      param_1->tlsext_ticket_expected = 3;
      *puVar4 = 0;
      *(undefined *)(param_1->tlsext_ecpointformatlist_length + 1) = 1;
      *(undefined *)(param_1->tlsext_ecpointformatlist_length + 2) = 2;
      if (param_1->tlsext_ellipticcurvelist_length != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      puVar4 = PTR_CRYPTO_malloc_006a8108;
      param_1->tlsext_ecpointformatlist = (uchar *)0x32;
      puVar4 = (undefined *)(*(code *)puVar4)(0x32,"t1_lib.c",0x6ed);
      param_1->tlsext_ellipticcurvelist_length = (size_t)puVar4;
      pcVar8 = (code *)PTR_ERR_put_error_006a9030;
      if (puVar4 != (undefined *)0x0) {
        puVar6 = pref_list;
        do {
          iVar5 = *(int *)puVar6;
          uVar7 = 2;
          if (iVar5 != 0x2d2) {
            if (iVar5 < 0x2d3) {
              uVar7 = 0x12;
              if (iVar5 != 0x2c7) {
                if (iVar5 < 0x2c8) {
                  uVar7 = 0xf;
                  if (iVar5 != 0x2c4) {
                    if (iVar5 < 0x2c5) {
                      if (iVar5 == 0x199) {
                        uVar7 = 0x13;
                      }
                      else {
                        uVar7 = 0x17;
                        if (iVar5 != 0x19f) {
                          uVar7 = 0;
                        }
                      }
                    }
                    else if (iVar5 == 0x2c5) {
                      uVar7 = 0x10;
                    }
                    else {
                      uVar7 = 0x11;
                      if (iVar5 != 0x2c6) {
                        uVar7 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar7 = 0x16;
                  if (iVar5 != 0x2ca) {
                    if (iVar5 < 0x2cb) {
                      if (iVar5 == 0x2c8) {
                        uVar7 = 0x14;
                      }
                      else {
                        uVar7 = 0x15;
                        if (iVar5 != 0x2c9) {
                          uVar7 = 0;
                        }
                      }
                    }
                    else {
                      uVar7 = 0x19;
                      if (iVar5 != 0x2cc) {
                        if (iVar5 < 0x2cc) {
                          uVar7 = 0x18;
                        }
                        else {
                          uVar7 = 1;
                          if (iVar5 != 0x2d1) goto LAB_0049750c;
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar7 = 8;
              if (iVar5 != 0x2d8) {
                if (iVar5 < 0x2d9) {
                  uVar7 = 5;
                  if (iVar5 != 0x2d5) {
                    if (iVar5 < 0x2d6) {
                      if (iVar5 == 0x2d3) {
                        uVar7 = 3;
                      }
                      else {
                        uVar7 = 4;
                        if (iVar5 != 0x2d4) {
                          uVar7 = 0;
                        }
                      }
                    }
                    else if (iVar5 == 0x2d6) {
                      uVar7 = 6;
                    }
                    else {
                      uVar7 = 7;
                      if (iVar5 != 0x2d7) {
                        uVar7 = 0;
                      }
                    }
                  }
                }
                else {
                  uVar7 = 0xb;
                  if (iVar5 != 0x2db) {
                    if (iVar5 < 0x2dc) {
                      if (iVar5 == 0x2d9) {
                        uVar7 = 9;
                      }
                      else {
                        uVar7 = 10;
                        if (iVar5 != 0x2da) {
                          uVar7 = 0;
                        }
                      }
                    }
                    else {
                      uVar7 = 0xd;
                      if (iVar5 != 0x2dd) {
                        if (iVar5 < 0x2dd) {
                          uVar7 = 0xc;
                        }
                        else {
                          uVar7 = 0xe;
                          if (iVar5 != 0x2de) {
LAB_0049750c:
                            uVar7 = 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar6 = (undefined1 *)((int)puVar6 + 4);
          *puVar4 = 0;
          puVar4[1] = uVar7;
          puVar4 = puVar4 + 2;
          if (puVar6 == nid_list) {
            return 1;
          }
        } while( true );
      }
      param_1->tlsext_ecpointformatlist = (uchar *)0x0;
      uVar3 = 0x6f0;
    }
    (*pcVar8)(0x14,0x119,0x41,"t1_lib.c",uVar3);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

