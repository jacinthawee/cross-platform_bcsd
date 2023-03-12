
int __regparm1 SSL_CTX_remove_session(SSL_CTX *param_1,SSL_SESSION *c)

{
  undefined *puVar1;
  void *pvVar2;
  SSL_SESSION *mode;
  int iVar3;
  int iVar4;
  void *in_stack_00000008;
  char *pcVar5;
  undefined4 uVar6;
  
  iVar4 = 0;
  if ((in_stack_00000008 != (void *)0x0) && (*(int *)((int)in_stack_00000008 + 0x44) != 0)) {
    CRYPTO_lock((int)param_1,9,&DAT_0000000c,(int)"ssl_sess.c");
    pvVar2 = lh_retrieve((_LHASH *)c->master_key_length,in_stack_00000008);
    if (in_stack_00000008 != pvVar2) {
      CRYPTO_lock((int)pvVar2,10,&DAT_0000000c,(int)"ssl_sess.c");
      return 0;
    }
    pvVar2 = lh_delete((_LHASH *)c->master_key_length,in_stack_00000008);
    mode = *(SSL_SESSION **)((int)in_stack_00000008 + 0xcc);
    if ((mode != (SSL_SESSION *)0x0) &&
       (puVar1 = *(undefined **)((int)in_stack_00000008 + 200), puVar1 != (undefined *)0x0)) {
      if (mode == (SSL_SESSION *)(c->master_key + 8)) {
        if (puVar1 == c->master_key + 4) {
          *(undefined4 *)(c->master_key + 4) = 0;
          *(undefined4 *)(c->master_key + 8) = 0;
          mode = c;
        }
        else {
          *(undefined **)(c->master_key + 8) = puVar1;
          *(SSL_SESSION **)(puVar1 + 0xcc) = mode;
        }
      }
      else if (puVar1 == c->master_key + 4) {
        *(SSL_SESSION **)(c->master_key + 4) = mode;
        *(undefined **)(mode->krb5_client_princ + 0x38) = puVar1;
      }
      else {
        *(undefined **)(mode->krb5_client_princ + 0x38) = puVar1;
        *(SSL_SESSION **)(*(int *)((int)in_stack_00000008 + 200) + 0xcc) = mode;
      }
      *(undefined4 *)((int)in_stack_00000008 + 0xcc) = 0;
      *(undefined4 *)((int)in_stack_00000008 + 200) = 0;
    }
    uVar6 = 0x2ce;
    pcVar5 = "ssl_sess.c";
    CRYPTO_lock((int)mode,10,&DAT_0000000c,(int)"ssl_sess.c");
    *(undefined4 *)((int)pvVar2 + 0x94) = 1;
    if (*(code **)(c->master_key + 0x18) != (code *)0x0) {
      (**(code **)(c->master_key + 0x18))(c,pvVar2,pcVar5,uVar6);
    }
    iVar4 = 1;
    iVar3 = CRYPTO_add_lock((int *)((int)pvVar2 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4);
    if (iVar3 < 1) {
      SSL_SESSION_free_part_2();
    }
  }
  return iVar4;
}

