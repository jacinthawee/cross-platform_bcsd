
void ssl_update_cache(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  time_t tm;
  SSL_CTX *s;
  
  if ((*(SSL_SESSION **)(param_1 + 0xc0))->session_id_length == 0) {
    return;
  }
  s = *(SSL_CTX **)(param_1 + 0x170);
  uVar2 = s->session_cache_mode;
  if (((uVar2 & param_2) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
    if ((uVar2 & 0x200) == 0) {
      iVar3 = SSL_CTX_add_session(s,*(SSL_SESSION **)(param_1 + 0xc0));
      if (iVar3 == 0) goto LAB_080c0cb8;
      s = *(SSL_CTX **)(param_1 + 0x170);
    }
    if (s->new_session_cb != (_func_3087 *)0x0) {
      CRYPTO_add_lock((int *)(*(int *)(param_1 + 0xc0) + 0xa4),1,0xe,"ssl_lib.c",0x982);
      iVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x28))
                        (param_1,*(undefined4 *)(param_1 + 0xc0));
      if (iVar3 == 0) {
        SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
      }
    }
  }
LAB_080c0cb8:
  if (((uVar2 & 0x80) == 0) && (param_2 == (uVar2 & param_2))) {
    if ((param_2 & 1) == 0) {
      cVar1 = *(char *)(*(int *)(param_1 + 0x170) + 0x48);
    }
    else {
      cVar1 = *(char *)(*(int *)(param_1 + 0x170) + 0x3c);
    }
    if (cVar1 == -1) {
      tm = time((time_t *)0x0);
      SSL_CTX_flush_sessions(*(SSL_CTX **)(param_1 + 0x170),tm);
      return;
    }
  }
  return;
}

