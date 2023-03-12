
int compute_key(uchar *param_1,BIGNUM *param_2,DH *param_3)

{
  int *piVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *r;
  BN_MONT_CTX *m_ctx;
  int in_GS_OFFSET;
  int reason;
  int line;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = BN_num_bits(param_3->p);
  if (iVar2 < 0x2711) {
    ctx = BN_CTX_new();
    if (ctx != (BN_CTX *)0x0) {
      BN_CTX_start(ctx);
      r = BN_CTX_get(ctx);
      if (param_3->priv_key == (BIGNUM *)0x0) {
        line = 0xe0;
        reason = 100;
LAB_08110a5f:
        iVar2 = -1;
        ERR_put_error(5,0x66,reason,"dh_key.c",line);
      }
      else {
        if ((*(byte *)&param_3->flags & 1) == 0) {
          m_ctx = (BN_MONT_CTX *)0x0;
LAB_08110985:
          iVar2 = DH_check_pub_key(param_3,param_2,&local_24);
          if ((iVar2 == 0) || (local_24 != 0)) {
            line = 0xf3;
            reason = 0x66;
          }
          else {
            iVar2 = (*param_3->meth->bn_mod_exp)
                              (param_3,r,param_2,param_3->priv_key,param_3->p,ctx,m_ctx);
            if (iVar2 != 0) {
              iVar2 = BN_bn2bin(r,param_1);
              goto LAB_081109e4;
            }
            line = 0xf9;
            reason = 3;
          }
          goto LAB_08110a5f;
        }
        m_ctx = BN_MONT_CTX_set_locked
                          (&param_3->method_mont_p,(int)&param_3->method_mont_p,(BIGNUM *)0x1a,
                           (BN_CTX *)param_3->p);
        if ((*(byte *)&param_3->flags & 2) == 0) {
          piVar1 = &param_3->priv_key->flags;
          *piVar1 = *piVar1 | 4;
        }
        if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_08110985;
        iVar2 = -1;
      }
LAB_081109e4:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      goto LAB_081109f8;
    }
  }
  else {
    ERR_put_error(5,0x66,0x67,"dh_key.c",0xd5);
  }
  iVar2 = -1;
LAB_081109f8:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

