
undefined4 ssl_prepare_clienthello_tlsext(SSL *param_1)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  undefined *puVar4;
  undefined uVar5;
  int iVar6;
  
  iVar6 = 0;
  p_Var1 = (_STACK *)SSL_get_ciphers(param_1);
  while( true ) {
    iVar3 = sk_num(p_Var1);
    if (iVar3 <= iVar6) {
      return 1;
    }
    pvVar2 = sk_value(p_Var1,iVar6);
    if (((*(byte *)((int)pvVar2 + 0xc) & 0xe0) != 0) ||
       ((*(uint *)((int)pvVar2 + 0x10) & 0x40) != 0)) break;
    iVar6 = iVar6 + 1;
  }
  if (param_1->version < 0x301) {
    return 1;
  }
  if ((void *)param_1->tlsext_ecpointformatlist_length != (void *)0x0) {
    CRYPTO_free((void *)param_1->tlsext_ecpointformatlist_length);
  }
  puVar4 = (undefined *)CRYPTO_malloc(3,"t1_lib.c",0x6c3);
  param_1->tlsext_ecpointformatlist_length = (size_t)puVar4;
  if (puVar4 == (undefined *)0x0) {
    iVar6 = 0x6c5;
  }
  else {
    param_1->tlsext_ticket_expected = 3;
    *puVar4 = 0;
    *(undefined *)(param_1->tlsext_ecpointformatlist_length + 1) = 1;
    *(undefined *)(param_1->tlsext_ecpointformatlist_length + 2) = 2;
    if ((void *)param_1->tlsext_ellipticcurvelist_length != (void *)0x0) {
      CRYPTO_free((void *)param_1->tlsext_ellipticcurvelist_length);
    }
    param_1->tlsext_ecpointformatlist = (uchar *)0x32;
    pvVar2 = CRYPTO_malloc(0x32,"t1_lib.c",0x6d5);
    param_1->tlsext_ellipticcurvelist_length = (size_t)pvVar2;
    if (pvVar2 != (void *)0x0) {
      iVar6 = 0;
      do {
        iVar3 = *(int *)(pref_list + iVar6 * 4);
        if (iVar3 == 0x2d2) {
          uVar5 = 2;
        }
        else if (iVar3 < 0x2d3) {
          if (iVar3 == 0x2c7) {
            uVar5 = 0x12;
          }
          else if (iVar3 < 0x2c8) {
            if (iVar3 == 0x2c4) {
              uVar5 = 0xf;
            }
            else if (iVar3 < 0x2c5) {
              uVar5 = 0x13;
              if ((iVar3 != 0x199) && (uVar5 = 0x17, iVar3 != 0x19f)) {
                uVar5 = 0;
              }
            }
            else {
              uVar5 = 0x10;
              if ((iVar3 != 0x2c5) && (uVar5 = 0x11, iVar3 != 0x2c6)) {
                uVar5 = 0;
              }
            }
          }
          else if (iVar3 == 0x2ca) {
            uVar5 = 0x16;
          }
          else if (iVar3 < 0x2cb) {
            uVar5 = 0x14;
            if ((iVar3 != 0x2c8) && (uVar5 = 0x15, iVar3 != 0x2c9)) {
              uVar5 = 0;
            }
          }
          else {
            uVar5 = 0x19;
            if (((iVar3 != 0x2cc) && (uVar5 = 0x18, 0x2cb < iVar3)) && (uVar5 = 1, iVar3 != 0x2d1))
            goto LAB_080ac1a2;
          }
        }
        else if (iVar3 == 0x2d8) {
          uVar5 = 8;
        }
        else if (iVar3 < 0x2d9) {
          if (iVar3 == 0x2d5) {
            uVar5 = 5;
          }
          else if (iVar3 < 0x2d6) {
            uVar5 = 3;
            if ((iVar3 != 0x2d3) && (uVar5 = 4, iVar3 != 0x2d4)) {
              uVar5 = 0;
            }
          }
          else {
            uVar5 = 6;
            if ((iVar3 != 0x2d6) && (uVar5 = 7, iVar3 != 0x2d7)) {
              uVar5 = 0;
            }
          }
        }
        else if (iVar3 == 0x2db) {
          uVar5 = 0xb;
        }
        else if (iVar3 < 0x2dc) {
          uVar5 = 9;
          if ((iVar3 != 0x2d9) && (uVar5 = 10, iVar3 != 0x2da)) {
            uVar5 = 0;
          }
        }
        else {
          uVar5 = 0xd;
          if (((iVar3 != 0x2dd) && (uVar5 = 0xc, 0x2dc < iVar3)) && (uVar5 = 0xe, iVar3 != 0x2de)) {
LAB_080ac1a2:
            uVar5 = 0;
          }
        }
        *(undefined *)((int)pvVar2 + iVar6 * 2) = 0;
        *(undefined *)((int)pvVar2 + iVar6 * 2 + 1) = uVar5;
        iVar6 = iVar6 + 1;
        if (iVar6 == 0x19) {
          return 1;
        }
      } while( true );
    }
    param_1->tlsext_ecpointformatlist = (uchar *)0x0;
    iVar6 = 0x6d8;
  }
  ERR_put_error(0x14,0x119,0x41,"t1_lib.c",iVar6);
  return 0xffffffff;
}

