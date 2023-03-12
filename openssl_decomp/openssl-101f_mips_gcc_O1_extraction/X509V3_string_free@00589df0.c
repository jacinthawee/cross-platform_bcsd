
void X509V3_string_free(X509V3_CTX *ctx,char *str)

{
  _func_4246 *UNRECOVERED_JUMPTABLE;
  
  if ((str != (char *)0x0) &&
     (UNRECOVERED_JUMPTABLE = ctx->db_meth->free_string, UNRECOVERED_JUMPTABLE != (_func_4246 *)0x0)
     ) {
                    /* WARNING: Could not recover jumptable at 0x00589e08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(ctx->db,str);
    return;
  }
  return;
}

