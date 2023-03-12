
void X509V3_set_ctx(X509V3_CTX *ctx,X509 *issuer,X509 *subject,X509_REQ *req,X509_CRL *crl,int flags
                   )

{
  ctx->issuer_cert = issuer;
  ctx->subject_cert = subject;
  ctx->crl = crl;
  ctx->subject_req = req;
  ctx->flags = flags;
  return;
}

