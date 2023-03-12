
void timeout_LHASH_DOALL_ARG(void *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  
  if ((param_2[1] == 0) ||
     (*(int *)((int)param_1 + 0xa8) + *(int *)((int)param_1 + 0xac) < param_2[1])) {
    lh_delete((_LHASH *)param_2[2],param_1);
    iVar3 = *(int *)((int)param_1 + 0xcc);
    iVar1 = *param_2;
    if ((iVar3 != 0) && (iVar2 = *(int *)((int)param_1 + 200), iVar2 != 0)) {
      if (iVar3 == iVar1 + 0x1c) {
        bVar5 = iVar2 != iVar1 + 0x18;
        if (bVar5) {
          *(int *)(iVar1 + 0x1c) = iVar2;
        }
        if (bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar3;
        }
        else {
          iVar3 = 0;
        }
        if (!bVar5) {
          *(int *)(iVar1 + 0x18) = iVar3;
        }
        if (!bVar5) {
          *(int *)(iVar1 + 0x1c) = iVar3;
        }
      }
      else {
        bVar5 = iVar2 == iVar1 + 0x18;
        if (!bVar5) {
          *(int *)(iVar3 + 200) = iVar2;
        }
        if (bVar5) {
          *(int *)(iVar1 + 0x18) = iVar3;
        }
        else {
          iVar2 = *(int *)((int)param_1 + 200);
        }
        if (bVar5) {
          *(int *)(iVar3 + 200) = iVar2;
        }
        if (!bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar3;
        }
      }
      *(undefined4 *)((int)param_1 + 0xcc) = 0;
      *(undefined4 *)((int)param_1 + 200) = 0;
      iVar1 = *param_2;
    }
    pcVar4 = *(code **)(iVar1 + 0x2c);
    *(undefined4 *)((int)param_1 + 0x94) = 1;
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(iVar1,param_1);
    }
    iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0xa4),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar1 < 1) {
      CRYPTO_free_ex_data(3,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0xc0));
      OPENSSL_cleanse((void *)((int)param_1 + 8),8);
      OPENSSL_cleanse((void *)((int)param_1 + 0x14),0x30);
      OPENSSL_cleanse((void *)((int)param_1 + 0x48),0x20);
      if (*(int *)((int)param_1 + 0x98) != 0) {
        ssl_sess_cert_free();
      }
      if (*(X509 **)((int)param_1 + 0x9c) != (X509 *)0x0) {
        X509_free(*(X509 **)((int)param_1 + 0x9c));
      }
      if (*(_STACK **)((int)param_1 + 0xbc) != (_STACK *)0x0) {
        sk_free(*(_STACK **)((int)param_1 + 0xbc));
      }
      if (*(void **)((int)param_1 + 0xd0) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xd0));
      }
      if (*(void **)((int)param_1 + 0xe4) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xe4));
      }
      *(undefined4 *)((int)param_1 + 0xd4) = 0;
      if (*(void **)((int)param_1 + 0xd8) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xd8));
      }
      *(undefined4 *)((int)param_1 + 0xdc) = 0;
      if (*(void **)((int)param_1 + 0xe0) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xe0));
      }
      if (*(void **)((int)param_1 + 0x8c) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x8c));
      }
      if (*(void **)((int)param_1 + 0x90) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0x90));
      }
      if (*(void **)((int)param_1 + 0xf0) != (void *)0x0) {
        CRYPTO_free(*(void **)((int)param_1 + 0xf0));
      }
      OPENSSL_cleanse(param_1,0xf4);
      CRYPTO_free(param_1);
      return;
    }
  }
  return;
}

