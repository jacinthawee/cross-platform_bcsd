
void usage(void)

{
  BIO_printf(bio_err,"Usage: pkeyutl [options]\n");
  BIO_printf(bio_err,"-in file        input file\n");
  BIO_printf(bio_err,"-out file       output file\n");
  BIO_printf(bio_err,"-sigfile file signature file (verify operation only)\n");
  BIO_printf(bio_err,"-inkey file     input key\n");
  BIO_printf(bio_err,"-keyform arg    private key format - default PEM\n");
  BIO_printf(bio_err,"-pubin          input is a public key\n");
  BIO_printf(bio_err,"-certin         input is a certificate carrying a public key\n");
  BIO_printf(bio_err,"-pkeyopt X:Y    public key options\n");
  BIO_printf(bio_err,"-sign           sign with private key\n");
  BIO_printf(bio_err,"-verify         verify with public key\n");
  BIO_printf(bio_err,"-verifyrecover  verify with public key, recover original data\n");
  BIO_printf(bio_err,"-encrypt        encrypt with public key\n");
  BIO_printf(bio_err,"-decrypt        decrypt with private key\n");
  BIO_printf(bio_err,"-derive         derive shared secret\n");
  BIO_printf(bio_err,"-hexdump        hex dump output\n");
  BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
  BIO_vprintf(bio_err,"-passin arg     pass phrase source\n",&stack0xfffffff8);
  return;
}

