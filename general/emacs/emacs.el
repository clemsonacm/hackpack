;; Better indenting for C/C++
(setq c-default-style "linux"
      c-basic-offset 4)

;; Place backup files somewhere out-of-the-way
(setq backup-directory-alist `(("." . "~/.saves")))

;; Compile more quickly
(global-set-key (kbd "C-c c") 'compile)

;; Line numbering
(setq linum-format "%4d \u2502")
(global-linum-mode t)

;; Get rid of scroll bars.
(menu-bar-mode -1)
(scroll-bar-mode -1)
(tool-bar-mode -1)

;; OOB theming is a new Emacs thing (versions >= 24)
;; If that's available, use a comfortable color scheme
(if (>= emacs-major-version 24)
    (load-theme 'misterioso))
