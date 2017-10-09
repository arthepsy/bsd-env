# $FreeBSD$

PORTNAME=	spf_fetch
PORTVERSION=	1.0.1.b
CATEGORIES=	mail

MAINTAINER=	moo@arthepsy.eu
COMMENT=	Utilities to look-up SPF records and manage whitelists

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/bin/dig:dns/bind-tools

OPTIONS_DEFINE=	SIPCALC
OPTIONS_DEFAULT=SIPCALC
OPTIONS_SUB=	yes
SIPCALC_DESC=	Use sipcalc to validate IPv4 and IPv6 addresses

USE_GITHUB=	yes
GH_ACCOUNT=	akpoff
GH_PROJECT=	spf_fetch
GH_TAGNAME=	1.0.1-beta

USES=		shebangfix

SPF_FILES=	spf_fetch spf_update_pf experimental/spf_mta_capture

SHEBANG_LANG=	sh
sh_OLD_CMD=	${SH}
sh_CMD=		${LOCALBASE}/bin/bash
SHEBANG_FILES=	${SPF_FILES} filters/filter_sipcalc

SIPCALC_RUN_DEPENDS=sipcalc:net-mgmt/sipcalc

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${PATCH_WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' \
		-e 's#\([ "'\'']\)\(/etc/mail\)#\1${LOCALBASE}\2#g' {} \;
.for spf_file in ${SPF_FILES}
	@${REINPLACE_CMD} -i '' -e 's#filters/#${LOCALBASE}/bin/spf_#g' \
		${PATCH_WRKSRC}/${spf_file}.1
	@${REINPLACE_CMD} -i '' -e 's#\[\[#[#g' -e 's#\]\]#]#g' -e 's#&&#] \&\& [#g' \
		${PATCH_WRKSRC}/${spf_file}
.endfor

do-build:

do-install:
.for spf_file in ${SPF_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${spf_file} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${spf_file}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
.if ${PORT_OPTIONS:MSIPCALC}
	${INSTALL_SCRIPT} ${WRKSRC}/filters/filter_sipcalc ${STAGEDIR}${PREFIX}/bin/spf_filter_sipcalc
.endif

.include <bsd.port.mk>
