call plug#begin('~/.local/share/nvim/plugged')

Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'nathanaelkane/vim-indent-guides'
Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'scrooloose/nerdcommenter'
Plug 'jiangmiao/auto-pairs'
Plug 'morhetz/gruvbox'

call plug#end()

let g:indent_guides_enable_on_vim_startup = 1
let g:NERDSpaceDelims = 1
let mapleader=","
let g:AutoPairsFlyMode = 1

syntax enable
filetype plugin on
set autoindent
set cursorline
set noshowmatch
set relativenumber
set nohlsearch
set hidden
set noerrorbells
set tabstop=4 softtabstop=4
set shiftwidth=4
set expandtab
set smartindent
set nu
set nowrap
set smartcase
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile
set incsearch
set scrolloff=8
set noshowmode

set splitbelow
set splitright

colorscheme gruvbox

nnoremap <silent> <A-h> <C-w>h
nnoremap <silent> <A-j> <C-w>j
nnoremap <silent> <A-k> <C-w>k
nnoremap <silent> <A-l> <C-w>l
tnoremap <silent> <ESC> <C-\><C-N>
nnoremap <silent> <A-t> :vsplit<CR>:terminal<CR>i
nnoremap <silent> <A-d> :NERDTree<CR>
