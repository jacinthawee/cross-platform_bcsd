
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  cert_st *pcVar28;
  int iVar29;
  uint uVar30;
  uchar *puVar31;
  _func_3154 *p_Var32;
  code *pcVar33;
  uint uVar34;
  uint in_a3;
  uint in_t0;
  uint in_t1;
  cert_st *pcVar35;
  
  pcVar35 = ssl->cert;
  if ((SSL_CTX *)ssl->psk_server_callback != ctx) {
    if (ctx == (SSL_CTX *)0x0) {
      ctx = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    pcVar28 = (cert_st *)ssl_cert_dup(ctx->cert);
    ssl->cert = pcVar28;
    if (pcVar35 != (cert_st *)0x0) {
      *(undefined4 *)(pcVar28 + 0x38) = *(undefined4 *)(pcVar35 + 0x38);
      *(undefined4 *)(pcVar28 + 0x44) = *(undefined4 *)(pcVar35 + 0x44);
      *(undefined4 *)(pcVar28 + 0x50) = *(undefined4 *)(pcVar35 + 0x50);
      *(undefined4 *)(pcVar28 + 0x5c) = *(undefined4 *)(pcVar35 + 0x5c);
      *(undefined4 *)(pcVar28 + 0x68) = *(undefined4 *)(pcVar35 + 0x68);
      *(undefined4 *)(pcVar28 + 0x74) = *(undefined4 *)(pcVar35 + 0x74);
      *(undefined4 *)(pcVar28 + 0x80) = *(undefined4 *)(pcVar35 + 0x80);
      *(undefined4 *)(pcVar28 + 0x8c) = *(undefined4 *)(pcVar35 + 0x8c);
      ssl_cert_free(pcVar35);
    }
    if (0x20 < ssl->sid_ctx_length) {
      OpenSSLDie("ssl_lib.c",0xb8e,"ssl->sid_ctx_length <= sizeof(ssl->sid_ctx)");
    }
    p_Var32 = ssl->psk_server_callback;
    if ((p_Var32 != (_func_3154 *)0x0) &&
       (uVar34 = ssl->sid_ctx_length, uVar34 == *(uint *)(p_Var32 + 0xc4))) {
      pcVar33 = p_Var32 + 200;
      puVar31 = ssl->sid_ctx;
      iVar29 = (*(code *)PTR_memcmp_006a9ad0)();
      if (iVar29 == 0) {
        uVar30 = ctx->sid_ctx_length;
        ssl->sid_ctx_length = uVar30;
        uVar1 = (uint)(ctx->sid_ctx + 4) & 3;
        iVar29 = *(int *)(ctx->sid_ctx + 4 + -uVar1);
        uVar2 = (uint)(ctx->sid_ctx + 8) & 3;
        iVar8 = *(int *)(ctx->sid_ctx + 8 + -uVar2);
        uVar3 = (uint)(ctx->sid_ctx + 0xc) & 3;
        iVar9 = *(int *)(ctx->sid_ctx + 0xc + -uVar3);
        uVar4 = (uint)(ctx->sid_ctx + 0x10) & 3;
        iVar10 = *(int *)(ctx->sid_ctx + 0x10 + -uVar4);
        uVar5 = (uint)(ctx->sid_ctx + 0x14) & 3;
        iVar11 = *(int *)(ctx->sid_ctx + 0x14 + -uVar5);
        uVar6 = (uint)(ctx->sid_ctx + 0x18) & 3;
        iVar12 = *(int *)(ctx->sid_ctx + 0x18 + -uVar6);
        uVar7 = (uint)(ctx->sid_ctx + 0x1c) & 3;
        iVar13 = *(int *)(ctx->sid_ctx + 0x1c + -uVar7);
        uVar14 = (uint)(ctx->sid_ctx + 7) & 3;
        uVar21 = *(uint *)(ctx->sid_ctx + 7 + -uVar14);
        uVar15 = (uint)(ctx->sid_ctx + 0xb) & 3;
        uVar22 = *(uint *)(ctx->sid_ctx + 0xb + -uVar15);
        uVar16 = (uint)(ctx->sid_ctx + 0xf) & 3;
        uVar23 = *(uint *)(ctx->sid_ctx + 0xf + -uVar16);
        uVar17 = (uint)(ctx->sid_ctx + 0x13) & 3;
        uVar24 = *(uint *)(ctx->sid_ctx + 0x13 + -uVar17);
        uVar18 = (uint)(ctx->sid_ctx + 0x17) & 3;
        uVar25 = *(uint *)(ctx->sid_ctx + 0x17 + -uVar18);
        uVar19 = (uint)(ctx->sid_ctx + 0x1b) & 3;
        uVar26 = *(uint *)(ctx->sid_ctx + 0x1b + -uVar19);
        uVar20 = (uint)(ctx->sid_ctx + 0x1f) & 3;
        uVar27 = *(uint *)(ctx->sid_ctx + 0x1f + -uVar20);
        *(undefined4 *)ssl->sid_ctx = *(undefined4 *)ctx->sid_ctx;
        *(uint *)(ssl->sid_ctx + 4) =
             (iVar29 << uVar1 * 8 | in_t1 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar14 + 1) * 8
             | uVar21 >> (3 - uVar14) * 8;
        *(uint *)(ssl->sid_ctx + 8) =
             (iVar8 << uVar2 * 8 | in_t0 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar15 + 1) * 8
             | uVar22 >> (3 - uVar15) * 8;
        *(uint *)(ssl->sid_ctx + 0xc) =
             (iVar9 << uVar3 * 8 | in_a3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar16 + 1) * 8
             | uVar23 >> (3 - uVar16) * 8;
        *(uint *)(ssl->sid_ctx + 0x10) =
             (iVar10 << uVar4 * 8 | uVar34 & 0xffffffffU >> (4 - uVar4) * 8) &
             -1 << (uVar17 + 1) * 8 | uVar24 >> (3 - uVar17) * 8;
        *(uint *)(ssl->sid_ctx + 0x14) =
             (iVar11 << uVar5 * 8 | (uint)pcVar33 & 0xffffffffU >> (4 - uVar5) * 8) &
             -1 << (uVar18 + 1) * 8 | uVar25 >> (3 - uVar18) * 8;
        *(uint *)(ssl->sid_ctx + 0x18) =
             (iVar12 << uVar6 * 8 | (uint)puVar31 & 0xffffffffU >> (4 - uVar6) * 8) &
             -1 << (uVar19 + 1) * 8 | uVar26 >> (3 - uVar19) * 8;
        *(uint *)(ssl->sid_ctx + 0x1c) =
             (iVar13 << uVar7 * 8 | uVar30 & 0xffffffffU >> (4 - uVar7) * 8) &
             -1 << (uVar20 + 1) * 8 | uVar27 >> (3 - uVar20) * 8;
      }
    }
    CRYPTO_add_lock(&ctx->references,1,0xc,"ssl_lib.c",0xb9d);
    p_Var32 = ssl->psk_server_callback;
    if ((p_Var32 == (_func_3154 *)0x0) ||
       (iVar29 = CRYPTO_add_lock((int *)(p_Var32 + 0x60),-1,0xc,"ssl_lib.c",0x795), 0 < iVar29)) {
      ssl->psk_server_callback = (_func_3154 *)ctx;
    }
    else {
      SSL_CTX_free_part_6(p_Var32);
      ssl->psk_server_callback = (_func_3154 *)ctx;
    }
  }
  return ctx;
}

